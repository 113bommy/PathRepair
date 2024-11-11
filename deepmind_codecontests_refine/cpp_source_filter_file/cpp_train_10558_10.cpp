#include <bits/stdc++.h>
using namespace std;
int const oo = 1e9;
int const mod = 1e9 + 7;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  string s1, s2;
  int i = 0, ind, d;
  cin >> s1;
  int l1 = s1.size();
  while (s1[i] != '|') i++;
  d = l1 - 1 - i;
  cin >> s2;
  int l2 = s2.size();
  if ((l1 + l2 - 1) % 2 == 0 && abs(i - d) <= l2) {
    ind = (l1 + l2 - 1) / 2 - i;
    for (int j = 0; j < int(l1); j++) {
      if (j == i) {
        for (int k = 0; k < int(ind); k++) {
          cout << s2[k];
        }
      }
      cout << s1[j];
    }
    for (int j = int(ind); j <= int(l2); j++) {
      cout << s2[j];
    }
    cout << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
