#include <bits/stdc++.h>
using namespace std;
const int NX = 200005;
int N, M, D[NX], L[NX], id[NX], cc[202];
bool fcmp(int a, int b) { return L[a] < L[b]; }
int main() {
  cin >> N;
  int S = 0, cmin;
  for (int i = 1; i <= N; i++) {
    cin >> L[i];
    id[i] = i;
  }
  for (int i = 1; i <= N; i++) {
    cin >> D[i];
    S += D[i];
  }
  cmin = S;
  sort(id + 1, id + N + 1, fcmp);
  for (int i = 1; i <= N;) {
    int j = i, s, n, c, k, d;
    s = n = 0;
    for (j = i; L[id[j]] == L[id[i]]; j++) {
      s += D[id[j]];
      n++;
    }
    k = i - (n - 1) - 1;
    c = 0;
    for (j = 1; j <= 200 && k; j++) {
      d = min(k, cc[j]);
      k -= d;
      c += d * j;
    }
    S -= s;
    c += S;
    cmin = min(c, cmin);
    for (j = i; L[id[j]] == L[id[i]]; j++) cc[D[id[j]]]++;
    i = j;
  }
  cout << cmin << endl;
  return 0;
}
