#include <bits/stdc++.h>
using namespace std;
set<pair<long long, long long> > s[301][301];
int main() {
  ios::sync_with_stdio(false);
  long long n, i, j, k, t[31], a[301][301];
  cin >> n;
  for (i = 0; i < n; i++) cin >> t[i];
  for (i = 0; i <= 300; i++)
    for (j = 0; j <= 300; j++) a[i][j] = 0;
  a[150][150] = 1;
  long long l;
  for (l = 0; l < t[0]; l++) a[150 - l][150] = 1;
  l--;
  s[150 - l][150].insert(make_pair(1, 1));
  for (i = 1; i < n; i++) {
    for (j = 0; j < 301; j++) {
      for (k = 0; k < 301; k++) {
        while (1) {
          auto it = s[j][k].lower_bound(make_pair(i, -1));
          if (it != s[j][k].end() && it->first == i) {
            if (it->second == 1) {
              for (l = 0; l < t[i]; l++) {
                a[j - l - 1][k - l - 1] = 1;
                a[j - l - 1][k + l + 1] = 1;
              }
              l--;
              s[j - l - 1][k - l - 1].insert(make_pair(i + 1, 8));
              s[j - l - 1][k + l + 1].insert(make_pair(i + 1, 2));
            }
            if (it->second == 2) {
              for (l = 0; l < t[i]; l++) {
                a[j - l - 1][k] = 1;
                a[j][k + l + 1] = 1;
              }
              l--;
              s[j - l - 1][k].insert(make_pair(i + 1, 1));
              s[j][k + l + 1].insert(make_pair(i + 1, 3));
            }
            if (it->second == 3) {
              for (l = 0; l < t[i]; l++) {
                a[j - l - 1][k + l + 1] = 1;
                a[j + l + 1][k + l + 1] = 1;
              }
              l--;
              s[j - l - 1][k + l + 1].insert(make_pair(i + 1, 2));
              s[j + l + 1][k + l + 1].insert(make_pair(i + 1, 4));
            }
            if (it->second == 4) {
              for (l = 0; l < t[i]; l++) {
                a[j][k + l + 1] = 1;
                a[j + l + 1][k] = 1;
              }
              l--;
              s[j][k + l + 1].insert(make_pair(i + 1, 3));
              s[j + l + 1][k].insert(make_pair(i + 1, 5));
            }
            if (it->second == 5) {
              for (l = 0; l < t[i]; l++) {
                a[j + l + 1][k - l - 1] = 1;
                a[j + l + 1][k + l + 1] = 1;
              }
              l--;
              s[j + l + 1][k - l - 1].insert(make_pair(i + 1, 4));
              s[j + l + 1][k + l + 1].insert(make_pair(i + 1, 6));
            }
            if (it->second == 6) {
              for (l = 0; l < t[i]; l++) {
                a[j][k - l - 1] = 1;
                a[j + l + 1][k] = 1;
              }
              l--;
              s[j][k - l - 1].insert(make_pair(i + 1, 7));
              s[j + l + 1][k].insert(make_pair(i + 1, 5));
            }
            if (it->second == 7) {
              for (l = 0; l < t[i]; l++) {
                a[j - l - 1][k - l - 1] = 1;
                a[j + l + 1][k - l - 1] = 1;
              }
              l--;
              s[j - l - 1][k - l - 1].insert(make_pair(i + 1, 8));
              s[j + l + 1][k - l - 1].insert(make_pair(i + 1, 6));
            }
            if (it->second == 8) {
              for (l = 0; l < t[i]; l++) {
                a[j - l - 1][k] = 1;
                a[j][k - l - 1] = 1;
              }
              l--;
              s[j - l - 1][k].insert(make_pair(i + 1, 1));
              s[j][k - l - 1].insert(make_pair(i + 1, 7));
            }
            s[j][k].erase(it);
          } else
            break;
        }
      }
    }
  }
  long long c = 0;
  for (i = 0; i < 301; i++) {
    for (j = 0; j < 301; j++) {
      if (a[i][j]) c++;
    }
  }
  cout << c;
  return 0;
}
