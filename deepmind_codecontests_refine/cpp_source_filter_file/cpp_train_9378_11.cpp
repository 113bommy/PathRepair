#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long aa[300000];
int arr[2000][2];
int l = 0;
int mark[100000];
int main() {
  queue<int> black, white;
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  set<int> w;
  for (int i = n - 1; i >= 0; i--) {
    aa[i] = w.size();
    w.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (!mark[a[i]]) {
      ans += aa[i];
      mark[a[i]] = 1;
    }
  }
  cout << ans;
}
