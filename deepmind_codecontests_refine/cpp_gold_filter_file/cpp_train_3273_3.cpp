#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int MODULE = 1000000007;
struct Node {
  vector<long long int> nbr;
  vector<long long int> cost;
  int used;
  int n;
  int v;
  Node() {
    used = 0;
    n = -1;
  }
  void push_back(int v, int c) {
    nbr.push_back(v);
    cost.push_back(c);
  }
};
long long int x, n, d;
vector<long long int> a, b;
long long int getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  long long int i;
  for (i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
vector<long long int> def() {
  vector<long long int> ans1;
  for (int i = 0; i < n; ++i) {
    long long int ans = 0;
    for (int j = 0; j <= i; ++j) {
      ans = max(ans, a[j] * b[i - j]);
    }
    ans1.push_back(ans);
  }
  for (int i = 0; i < n; ++i) {
    cout << ans1[i] << " ";
  }
  return ans1;
}
struct St {
  int n;
  string name;
  int t;
  bool operator<(const St& b) const {
    if (t == b.t) {
      return n < b.n;
    } else {
      return t < b.t;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  vector<pair<int, int> > arr(n);
  map<long long int, long long int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
    mp[arr[i].first]++;
  }
  for (int i = 0; i < n; ++i) {
    long long int ans = (n - 1) * 2;
    long long int a, b;
    a = ans / 2 + mp[arr[i].second];
    b = ans - a;
    cout << a << " " << b;
    cout << "\n";
  }
  return 0;
}
