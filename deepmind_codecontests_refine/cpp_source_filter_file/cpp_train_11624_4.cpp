#include <bits/stdc++.h>
using namespace std;
long long k, n;
long long b[200011];
vector<long long> a[3];
string s;
int main() {
  cin >> n >> k;
  for (long long i = (long long)(0); i < (long long)(n); i++) {
    cin >> b[i];
  }
  cin >> s;
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (long long i = (long long)(0); i < (long long)(n); i++) {
    if (s[i] == 'R') a[0].push_back(b[i]);
    if (s[i] == 'W') a[1].push_back(b[i]);
    if (s[i] == 'O') a[2].push_back(b[i]);
  }
  sort((a[0]).begin(), (a[0]).end());
  reverse((a[0]).begin(), (a[0]).end());
  sort((a[1]).begin(), (a[1]).end());
  reverse((a[1]).begin(), (a[1]).end());
  sort((a[2]).begin(), (a[2]).end());
  reverse((a[2]).begin(), (a[2]).end());
  long long resa = -1, resb = -1;
  if (a[0].size() > 0 && a[2].size() > 0 && a[0].size() + a[2].size() >= k) {
    long long i = 0, j = 0;
    resa = 0;
    while (i < a[0].size() && j < a[2].size() && i + j < k - 1) {
      if (a[0][i] < a[2][j]) {
        resa += a[2][j];
        j++;
      } else {
        resa += a[0][i];
        i++;
      }
    }
    while (i < a[0].size() && i + j < k - 1) {
      resa += a[0][i];
      i++;
    }
    while (j < a[2].size() && i + j < k - 1) {
      resa += a[2][j];
      j++;
    }
    if (i == 0) {
      resa += a[0][0];
      i++;
    } else if (j == 0) {
      resa += a[2][0];
      j++;
    } else {
      if (i < a[0].size() && j < a[2].size()) {
        resa += max(a[0][i], a[2][j]);
        i++;
      } else {
        if (i < a[0].size()) {
          resa += a[0][i];
          i++;
        } else {
          resa += a[2][j];
          j++;
        }
      }
    }
  }
  if (a[1].size() > 0 && a[2].size() > 0 && a[1].size() + a[2].size() >= k) {
    long long i = 0, j = 0;
    resb = 0;
    while (i < a[1].size() && j < a[2].size() && i + j < k - 1) {
      if (a[1][i] < a[2][j]) {
        resb += a[2][j];
        j++;
      } else {
        resb += a[1][i];
        i++;
      }
    }
    while (i < a[1].size() && i + j < k - 1) {
      resb += a[1][i];
      i++;
    }
    while (j < a[2].size() && i + j < k - 1) {
      resb += a[2][j];
      j++;
    }
    if (i == 0) {
      resb += a[1][0];
      i++;
    } else if (j == 0) {
      resb += a[2][0];
      j++;
    } else {
      if (i < a[1].size() && j < a[2].size()) {
        resb += max(a[1][i], a[2][j]);
        i++;
      } else {
        if (i < a[1].size()) {
          resb += a[1][i];
          i++;
        } else {
          resb += a[2][j];
          j++;
        }
      }
    }
  }
  cout << max(resa, resb) << endl;
  return 0;
}
