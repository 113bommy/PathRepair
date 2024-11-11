#include <bits/stdc++.h>
using namespace std;
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
unsigned long long int maxl(unsigned long long int a,
                            unsigned long long int b) {
  if (a > b) return a;
  return b;
}
unsigned long long int minl(unsigned long long int a,
                            unsigned long long int b) {
  if (a > b) return b;
  return a;
}
unsigned long long int mod = 1000000007;
unsigned long long int mulmod(unsigned long long int a,
                              unsigned long long int b,
                              unsigned long long int c) {
  unsigned long long int res = 0;
  a = a % c;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res + a) % c;
    }
    a = (a * 2) % c;
    b /= 2;
  }
  return res % c;
}
unsigned long long int power(unsigned long long int x,
                             unsigned long long int y) {
  unsigned long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int a[100005];
int tree[200005];
void build(int st, int low, int high) {
  if (low == high) {
    tree[st] = a[high] % 2;
    return;
  }
  int mid = low + (high - low) / 2;
  build(2 * st, low, mid);
  build(2 * st + 1, mid + 1, high);
  tree[st] = tree[2 * st] + tree[2 * st + 1];
}
void update(int st, int start, int end, int ind, int val) {
  if (start == end) {
    tree[st] = val % 2;
    return;
  }
  int mid = start + (end - start) / 2;
  if (ind <= mid) {
    update(2 * st, start, mid, ind, val);
  } else
    update(2 * st + 1, mid + 1, end, ind, val);
  tree[st] = tree[2 * st] + tree[2 * st + 1];
}
int query(int st, int start, int end, int low, int high) {
  if (start > high || end < low) return 0;
  int mid = start + (end - start) / 2;
  if (start == low && end == high) {
    return tree[st];
  }
  if (low > mid) return query(2 * st + 1, mid + 1, end, low, high);
  if (high <= mid) return query(2 * st, start, mid, low, high);
  return query(2 * st, start, mid, low, mid) +
         query(2 * st + 1, mid + 1, end, mid + 1, high);
}
unsigned long long int h(vector<unsigned long long int> a) {
  unsigned long long int ans = 0;
  unsigned long long int ind = 1;
  for (int i = 0; i < a.size(); i++) {
    ans += a[i] * power(31, ind);
    ans %= mod;
    ind++;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  unsigned long long int n, m;
  cin >> n >> m;
  vector<vector<unsigned long long int> > v(n + 1);
  for (int i = 0; i < m; i++) {
    unsigned long long int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  map<unsigned long long int, vector<unsigned long long int> > grp;
  vector<int> val(n + 1);
  for (int i = 1; i <= n; i++) {
    if (v[i].size() == 0) {
      cout << "-1" << endl;
      return 0;
    }
    sort(v[i].begin(), v[i].end());
    grp[h(v[i])].push_back(i);
  }
  if (grp.size() != 3) {
    cout << "-1" << endl;
    return 0;
  }
  int col = 1;
  for (auto it = grp.begin(); it != grp.end(); ++it) {
    for (int i = 0; i < it->second.size(); i++) {
      val[it->second[i]] = col;
    }
    col++;
  }
  for (int i = 1; i <= n; i++) {
    cout << val[i] << " ";
  }
  cout << endl;
  return 0;
}
