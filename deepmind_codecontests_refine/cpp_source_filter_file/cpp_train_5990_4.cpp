#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  gcd(b, a % b);
}
long long int b[1000009];
void sieve() {
  int i, j;
  for (i = 2; i < 1000009; i++) {
    if (i == 0) {
      for (j = 2 * i; j < 1000009; j = j + i) b[j] = 1;
    }
  }
}
bool checknumber(long long int n) {
  long long int k = n;
  long long int sum = 0;
  while (k > 0) {
    sum = sum + k % 10;
    k = k / 10;
  }
  if (sum == 10)
    return true;
  else
    return false;
}
int binarysearch(int a[], int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + high;
    mid = mid / 2;
    if (a[mid] == key) return mid + 1;
    if (a[low] == key) return low + 1;
    if (a[high] == key) return high + 1;
    if (a[mid] > key)
      high = mid;
    else
      low = mid;
    if (high - low == 1) {
      if (a[low] == key)
        return low + 1;
      else if (a[high] == key)
        return high + 1;
      else if ((a[low] < key) && (a[high] > key))
        return low + 1;
    }
  }
}
int a[101][101][101], k;
int cal(int m, vector<int> &ans) {
  int i, j, k, o;
  int colour[m + 1];
  memset(colour, 0, sizeof(colour));
  for (i = 1; i < ans.size(); i++) {
    int fr = ans[i], back = ans[i - 1];
    for (j = 1; j <= m; j++) {
      colour[j] += a[back][fr][j];
    }
  }
  k = ans.size() - 1;
  o = 0;
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  for (i = 1; i <= m; i++) {
    if (colour[i] == k) o++;
  }
  cout << "KK" << o << endl;
  ans.clear();
  return o;
}
void dfs(int u, int v, vector<int> adj[], int visited[], int &xc, int &k) {
  visited[u] = 1;
  for (auto x : adj[u]) {
    if ((visited[x] == 0) && (a[u][x][xc] > 0)) {
      if ((x == v)) {
        k++;
        return;
      }
      visited[x] = 1;
      dfs(x, v, adj, visited, xc, k);
    }
  }
}
int gcdExtended(int a, int b, int *x, int *y);
int modInverse(int a, int m) {
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else {
    int res = (x % m + m) % m;
    return res;
  }
}
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
void recursion(char ch, int n, int &count, string s[], vector<int> v[]) {
  if (n == 2) {
    count = count + v[ch - 'a'].size();
    return;
  }
  for (int i = 0; i < v[ch - 'a'].size(); i++) {
    int num = v[0][i];
    recursion(s[num][0], n - 1, count, s, v);
  }
}
int main() {
  int n, i, j, k, t, m, l;
  cin >> n >> m;
  string s[m];
  vector<int> v[6];
  for (i = 0; i < m; i++) {
    char a;
    cin >> s[i] >> a;
    v[a - 'a'].push_back(i);
  }
  int sum = 0;
  if (n > 2) {
    for (i = 0; i < v[0].size(); i++) {
      int count = 0;
      int num = v[0][i];
      recursion(s[num][0], n - 1, count, s, v);
      sum = sum + count;
    }
    cout << sum << endl;
  } else {
    cout << v[0].size();
  }
}
