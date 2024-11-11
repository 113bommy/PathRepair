#include <bits/stdc++.h>
using namespace std;
long long st, spm[100000], itb, it, k, ob[100000], f, n, sp, m, i, j;
int main() {
  cin >> n;
  sp = 1e15;
  spm[0] = 1e15;
  ob[0] = 1;
  for (i = 0; i < n; i++) {
    cin >> f;
    if (f == 1) {
      cin >> sp;
      while (sp > spm[it]) {
        it--;
        k++;
      }
    }
    if (f == 2) {
      while (!ob[itb]) {
        k++;
        itb--;
      }
    }
    if (f == 3) {
      it++;
      cin >> spm[it];
      if (spm[it] < sp) it--, k++;
    }
    if (f == 4) {
      itb++;
      ob[itb] = 1;
    }
    if (f == 6) {
      itb++;
      ob[itb] = 0;
    }
    if (f == 5) {
      it++;
      spm[it] = 1e15;
    }
  }
  cout << k << endl;
  return 0;
}
