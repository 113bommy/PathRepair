#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  int n;
  cin >> n >> a >> b;
  while (b.back() == a.back()) a.pop_back(), b.pop_back();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  while (b.back() == a.back()) a.pop_back(), b.pop_back();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if (a.size() == 1) {
    cout << 2 << "\n";
    return 0;
  }
  n = a.size();
  bool f1 = 1, f2 = 1;
  for (int i = 0; i < n - 1; ++i)
    if (a[i] != b[i + 1]) f1 = 0;
  for (int i = 0; i < n - 1; ++i)
    if (a[i + 1] != b[i]) f2 = 0;
  cout << (int)(f1 + f2) << "\n";
  return 0;
}
