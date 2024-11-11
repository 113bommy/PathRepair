#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k, n;
    cin >> n >> k;
    string second;
    cin >> second;
    bool ok = 1;
    for (int i = 0; i < second.size(); i++) {
      if (second[i] == '?') continue;
      if (i + k < second.size()) {
        if (second[i] != second[i + k] && second[i + k] != '?') {
          ok = 0;
          break;
        }
        second[i + k] = second[i];
      }
      if (i - k >= 0) {
        if (second[i] != second[i - k] && second[i - k] != '?') {
          ok = 0;
          break;
        }
        second[i - k] = second[i];
      }
    }
    int z = 0, o = 0, q = 0, j = 0;
    for (int i = 0; i < second.size(); i++, j++) {
      if (j == k) {
        if (o > z) {
          if (o - z > q) {
            ok = 0;
            break;
          }
        } else if (o < z) {
          if (z - o > q) {
            ok = 0;
            break;
          }
        } else if (!o && !z) {
          if (q % 2) {
            ok = 0;
            break;
          }
        }
        if (second[i - k] == '1')
          o--;
        else if (second[i - k] == '0')
          z--;
        else
          q--;
        j = 0;
      }
      if (second[i] == '0') z++;
      if (second[i] == '1') o++;
      if (second[i] == '?') q++;
    }
    if (j == k) {
      if (o > z) {
        if (o - z > q) {
          ok = 0;
        }
      } else if (o < z) {
        if (z - o > q) {
          ok = 0;
        }
      } else if (!o && !z) {
        if (q % 2) {
          ok = 0;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
