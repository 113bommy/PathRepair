#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e9 + 7;
const int N = 1e6 + 100;
long long int n, k, f[N];
bool ex = 0;
string s, z;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = s.size();
  for (int i = 1; i < n; i++) {
    while (k > 0 && s[k] != s[i]) k = f[k];
    if (s[k] == s[i]) k++;
    f[i + 1] = k;
  }
  if (f[n] != 0) {
    for (long long int i = 0; i < f[n]; i++) z += s[i];
    for (long long int i = f[n]; i < n - f[n]; i++) {
      if (f[i] == f[n]) ex = 1;
    }
    if (ex)
      cout << z;
    else {
      if (f[f[n]] == 0) {
        cout << "Just a legend";
        return 0;
      }
      z.clear();
      for (long long int i = 0; i < f[f[n]]; i++) z += s[i];
      cout << z;
    }
  } else
    cout << "Just a legend";
}
