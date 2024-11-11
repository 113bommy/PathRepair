#include <bits/stdc++.h>
using namespace std;
bool help(int a[], int n) {
  if (n == 1) return true;
  unordered_map<int, int> m;
  for (int i = 0; i < n; i++) m[a[i]]++;
  int mx = 0;
  for (auto i : m) mx = max(i.second, mx);
  if (n % 2) {
    if (mx > (n / 2 + 1))
      return false;
    else
      return true;
  } else {
    if (mx > n / 2)
      return false;
    else
      return true;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (help(a, n))
    cout << "YES";
  else
    cout << "NO";
}
