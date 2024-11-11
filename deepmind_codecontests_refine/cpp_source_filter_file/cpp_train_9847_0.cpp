#include <bits/stdc++.h>
using namespace std;
void preprocess(void) { return; }
int main(void) {
  preprocess();
  int t;
  t = 1;
  for (int z = 1; z <= t; z++) {
    int n, m;
    scanf("%d", &n), scanf("%d", &m);
    map<string, int> k;
    int bits[n][m];
    vector<pair<int, pair<int, int> > > opr(n);
    for (int i = 0; i < n; i++) {
      char var[11];
      scanf("%s", var);
      k[string(var)] = i;
      char temp[3];
      scanf("%s", temp);
      char bin[max(m + 1, 11)];
      scanf("%s", bin);
      if (bin[0] == '0' || bin[0] == '1') {
        opr[i].first = 0;
        for (int j = 0; j < m; j++) {
          bits[i][j] = bin[j] - '0';
        }
      } else {
        if (bin[0] == '?') {
          opr[i].second.first = -1;
        } else {
          opr[i].second.first = k[string(bin)];
        }
        char bit[4];
        scanf("%s", bit);
        if (bit[0] == 'O') {
          opr[i].first = 1;
        } else if (bit[1] == 'A') {
          opr[i].first = 2;
        } else {
          opr[i].first = 3;
        }
        scanf("%s", bin);
        if (bin[0] == '?') {
          opr[i].second.second = -1;
        } else {
          opr[i].second.second = k[string(bin)];
        }
      }
    }
    vector<int> mx(m), mn(m);
    for (int bit = 0; bit < m; bit++) {
      int temp[2] = {0};
      vector<int> aux(n);
      for (int peter = 0; peter < 2; peter++) {
        for (int i = 0; i < n; i++) {
          if (opr[i].first == 0) {
            aux[i] = bits[i][bit];
          } else {
            int bit1, bit2;
            if (opr[i].second.first == -1) {
              bit1 = peter;
            } else {
              bit1 = aux[opr[i].second.first];
            }
            if (opr[i].second.second == -1) {
              bit2 = peter;
            } else {
              bit2 = aux[opr[i].second.second];
            }
            if (opr[i].first == 1) {
              aux[i] = bit1 | bit2;
            } else if (opr[i].first == 2) {
              aux[i] = bit1 & bit2;
            } else {
              aux[i] = bit1 ^ bit2;
            }
          }
        }
        for (int i = 0; i < n; i++) {
          temp[peter] += aux[i];
        }
      }
      if (temp[0] < temp[1]) {
        mx[bit] = 1;
        mn[bit] = 0;
      } else if (temp[0] > temp[1]) {
        mx[bit] = 0;
        mn[bit] = 1;
      } else {
        mx[bit] = mn[bit] = 0;
      }
    }
    for (int i = 0; i < m - 1; i++) {
      printf("%d", mn[i]);
    }
    printf("%d\n", mn[m - 1]);
    for (int i = 0; i < m - 1; i++) {
      printf("%d", mx[i]);
    }
    printf("%d\n", mx[m - 1]);
  }
  return 0;
}
