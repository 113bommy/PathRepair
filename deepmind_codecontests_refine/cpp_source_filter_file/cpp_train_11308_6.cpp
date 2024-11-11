#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
int N;
int pibi[MAXN];
int pibi1[MAXN];
int query(int x, int y) {
  cout << x << ' ' << y << endl;
  int r;
  cin >> r;
  return r;
}
int aperm[MAXN], acnt;
int perm[MAXN], berm[MAXN];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    pibi[i] = query(i, i);
    pibi1[i] = query(i, (i + 1) % N);
  }
  cout << '!' << endl;
  for (int i = 0; i < N; i++) {
    perm[0] = i;
    for (int j = 1; j < N; j++) {
      perm[j] = perm[j - 1] ^ pibi1[j - 1] ^ pibi[j];
    }
    for (int j = 0; j < N; j++) {
      berm[perm[j]] = j;
    }
    bool ok = true;
    for (int j = 0; j < N; j++) {
      if ((perm[j] ^ berm[j]) != pibi[j]) {
        ok = false;
        break;
      }
      if ((perm[j] ^ berm[(j + 1) % N]) != pibi1[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      if ((acnt++) == 0) {
        memcpy(aperm, perm, sizeof(perm));
      }
    }
  }
  cout << acnt << endl;
  for (int i = 0; i < N; i++) {
    cout << aperm[i] << ' ';
  }
  cout << endl;
}
