#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  string s[n];
  for (long long int i = 0; i < n; i++) cin >> s[i];
  long long int fr = 0, frtemp = 0;
  for (long long int i = 0; i < n; i++) {
    frtemp = 0;
    for (long long int j = 0; j < n; j++) {
      if (s[i][j] == '.') {
        frtemp = 1;
        break;
      }
    }
    if (!frtemp) {
      fr = 1;
      break;
    }
  }
  long long int fc = 0, fctemp = 0;
  for (long long int i = 0; i < n; i++) {
    fctemp = 0;
    for (long long int j = 0; j < n; j++) {
      if (s[j][i] == '.') {
        fctemp = 1;
        break;
      }
    }
    if (!fctemp) {
      fc = 1;
      break;
    }
  }
  if (fc && fr) {
    cout << "-1"
         << "\n";
    return 0;
  }
  if (!fr) {
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < n; j++) {
        if (s[i][j] == '.') {
          cout << i + 1 << " " << j + 1 << "\n";
          break;
        }
      }
    }
    return 0;
  }
  if (!fc) {
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < n; j++) {
        if (s[j][i] == '.') {
          cout << j + 1 << " " << i + 1 << "\n";
          break;
        }
      }
    }
    return 0;
  }
}
