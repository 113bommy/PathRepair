#include <bits/stdc++.h>
using namespace std;
int main() {
  double sa[6];
  sa[0] = 1.0 / 1;
  sa[1] = 1.0 / 2;
  sa[2] = 1.0 / 4;
  sa[3] = 1.0 / 8;
  sa[4] = 1.0 / 16;
  sa[5] = 1.0 / 32;
  int n;
  cin >> n;
  int cs[5];
  double vm[5];
  double pm[5];
  for (int i = 0; i < 5; i++) {
    cs[i] = 0;
    int vs;
    cin >> vs;
    if (vs == -1) {
      vm[i] = 0;
      continue;
    }
    cs[i]++;
    vm[i] = (1 - (double)vs / 250);
  }
  for (int i = 0; i < 5; i++) {
    int vs;
    cin >> vs;
    if (vs == -1) {
      pm[i] = 0;
      continue;
    }
    cs[i]++;
    pm[i] = (1 - (double)vs / 250);
  }
  for (int i = 2; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int vs;
      cin >> vs;
      if (vs >= 0) {
        cs[j]++;
      }
    }
  }
  double fd[5];
  int bc[5];
  for (int i = 0; i < 5; i++) {
    fd[i] = cs[i] / (double)n;
    bc[i] = 1;
    while (bc[i] < 6 && sa[bc[i]] > fd[i]) {
      bc[i]++;
    }
  }
  long long vas = 2e9;
  int pla[5];
  for (pla[0] = 1; pla[0] < 7; pla[0]++) {
    for (pla[1] = 1; pla[1] < 7; pla[1]++) {
      for (pla[2] = 1; pla[2] < 7; pla[2]++) {
        for (pla[3] = 1; pla[3] < 7; pla[3]++) {
          for (pla[4] = 1; pla[4] < 7; pla[4]++) {
            long long mn = 0;
            long long mx = 1e9 + 7;
            int vs = 0;
            int ps = 0;
            for (int i = 0; i < 5; i++) {
              vs += 500 * pla[i] * vm[i];
              ps += 500 * pla[i] * pm[i];
              if (vm[i] == 0) {
                if (pm[i] == 0 || pla[i] == 6) {
                  continue;
                }
                double wc = sa[pla[i]];
                long long nmx = cs[i] / wc;
                nmx -= n;
                nmx--;
                mx = min(mx, nmx);
              }
              if (pla[i] > bc[i]) {
                double rd = sa[pla[i] - 1];
                long long nmn = cs[i] / rd;
                nmn -= n;
                mn = max(nmn, mn);
                continue;
              }
              if (pla[i] < bc[i]) {
                double rd = sa[pla[i]];
                rd = 1 - rd;
                int cnr = n - cs[i];
                long long nmn = cnr / rd;
                nmn++;
                nmn -= n;
                mn = max(nmn, mn);
                continue;
              }
            }
            if (vs < ps) {
              continue;
            }
            if (mn > mx) {
              continue;
            }
            vas = min(mn, vas);
          }
        }
      }
    }
  }
  if (vas > 1e9 + 7) {
    cout << -1 << endl;
    return 0;
  }
  cout << vas << endl;
  cin >> vas;
}
