#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int BIT = 17;
int n, m;
int P[N];
int pot2[33];
set<int> S[18];
set<int>::iterator it;
long long sol;
inline int find(int bit, int pos) {
  if (S[bit].empty()) return 0;
  it = S[bit].lower_bound(pos);
  if (it == S[bit].begin()) return 0;
  it--;
  return *it + 1;
}
inline int find2(int bit, int pos) {
  if (S[bit].empty()) return n - 1;
  it = S[bit].lower_bound(pos);
  if (it == S[bit].end()) return n - 1;
  return *it - 1;
}
inline void load() {
  pot2[0] = 1;
  for (int i = 1; i <= BIT; i++) pot2[i] = (pot2[i - 1] << 1);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &P[i]);
    x = P[i];
    for (int j = BIT; j >= 0; j--) {
      if (x & (1 << j)) {
        sol += (long long)pot2[j] * (i - find(j, i) + 1);
      } else
        S[j].insert(i);
    }
  }
}
inline void print() {
  printf("SADRZAJ NA MJESTU == %d\n", 1);
  for (set<int>::iterator it = S[0].begin(); it != S[0].end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
  system("pause");
}
inline void solve() {
  for (; m; m--) {
    int pos, val;
    scanf("%d %d", &pos, &val);
    pos--;
    for (int j = BIT; j >= 0; j--) {
      if (val & (1 << j)) {
        if ((P[pos] & (1 << j)) == 0) {
          S[j].erase(pos);
          sol += (long long)pot2[j] * (pos - find(j, pos) + 1) *
                 (find2(j, pos) - pos + 1);
        }
      } else {
        if ((P[pos] & (1 << j))) {
          int gore = pos - find(j, pos) + 1;
          int dole = find2(j, pos) - pos;
          sol -= (long long)pot2[j] * dole * gore;
          sol -= (long long)pot2[j] * gore;
          S[j].insert(pos);
        }
      }
    }
    P[pos] = val;
    cout << sol << endl;
  }
}
int main(void) {
  load();
  solve();
  return 0;
}
