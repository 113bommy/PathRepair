#include <bits/stdc++.h>
using namespace std;
const int oo = 999999999;
const double PI = 3.1415931;
const double eps = 1e-9;
const int maxN = 100 + 10;
bool satr[maxN], sotun[maxN];
pair<int, int> satr1[maxN], sotun1[maxN];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      if (c == '.') {
        satr[i] = true;
        satr1[i].first = i;
        satr1[i].second = j;
        sotun[j] = true;
        sotun1[j].first = i;
        sotun1[j].second = j;
      }
    }
  }
  bool rows = true, col = true;
  for (int i = 1; i <= n; i++) {
    rows &= satr[i];
    col &= sotun[i];
  }
  for (int i = 1; i <= n; i++) {
    if (!satr[i] && !col) {
      cout << -1;
      return 0;
    }
    if (!sotun[i] && !rows) {
      cout << -1;
      return 0;
    }
  }
  if (col) {
    for (int i = 1; i <= n; i++)
      cout << sotun1[i].first << " " << sotun1[i].second << endl;
  } else if (rows) {
    for (int i = 1; i <= n; i++)
      cout << satr1[i].first << " " << satr1[i].second << endl;
  } else
    cout << -1;
  return 0;
}
