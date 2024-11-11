#include <bits/stdc++.h>
using namespace std;
pair<char, int> v[5];
char a[55][55];
bool cstm(pair<char, int> a, pair<char, int> b) { return a.second > b.second; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  v[1].first = 'A', v[2].first = 'B', v[3].first = 'C', v[4].first = 'D';
  cin >> v[1].second >> v[2].second >> v[3].second >> v[4].second;
  sort(v + 1, v + 5, cstm);
  v[3].second--;
  v[4].second--;
  int k = 1;
  do {
    for (int i = (int)1; i <= (int)50; i++) {
      if (!(i & 1)) {
        if (v[4].second == 0) {
          a[k][i] = v[3].first;
        } else {
          a[k][i] = v[4].first;
          v[4].second--;
        }
      } else {
        a[k][i] = v[3].first;
      }
    }
    k++;
    for (int i = (int)1; i <= (int)50; i++) a[k][i] = v[3].first;
    k++;
  } while (v[4].second > 0);
  int j = 1;
  do {
    for (int i = (int)1; i <= (int)50; i++) a[k][i] = v[4].first;
    k++;
    for (int i = (int)1; i <= (int)50; i++) {
      if (v[j].second == 0) j++;
      if (!(i & 1) && j < 4) {
        a[k][i] = v[j].first;
        v[j].second--;
      } else {
        a[k][i] = v[4].first;
      }
    }
    k++;
  } while (v[1].second > 0 || v[2].second > 0 || v[3].second > 0);
  cout << k << " " << 50 << "\n";
  for (int i = (int)1; i <= (int)k; i++) {
    for (int j = (int)1; j <= (int)50; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
  return 0;
}
