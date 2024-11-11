#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  char spC[3];
  spC[0] = 'a';
  spC[1] = 'b';
  spC[2] = 'c';
  while (t--) {
    string ent;
    cin >> ent;
    if (ent[0] == '?') {
      for (int i = 0; i < 3; i++) {
        if (spC[i] != ent[1]) {
          ent[0] = spC[i];
          break;
        }
      }
    }
    if (ent[ent.length() - 1] == '?') {
      for (int i = 0; i < 3; i++) {
        if (spC[i] != ent[ent.length() - 2]) {
          ent[ent.length() - 1] = spC[i];
          break;
        }
      }
    }
    for (int i = 1; i < ent.length() - 1; i++) {
      if (ent[i] == '?') {
        for (int j = 0; j < 3; j++) {
          if (spC[j] != ent[i - 1] && spC[j] != ent[i + 1]) {
            ent[i] = spC[j];
            break;
          }
        }
      }
    }
    int condi = 0;
    for (int i = 1; i < ent.length() - 1; i++) {
      if (ent[i] == ent[i - 1] || ent[i] == ent[i + 1]) {
        condi = 1;
        break;
      }
    }
    if (condi)
      printf("-1\n");
    else
      cout << ent << endl;
  }
  return 0;
}
