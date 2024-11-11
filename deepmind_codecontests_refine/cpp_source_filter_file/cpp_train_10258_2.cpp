#include <bits/stdc++.h>
using namespace std;
const int MAXN = 600000;
const int MAXM = 200000;
const int INF = 1000000010;
const long long int MOD = 1000000007;
const long long int P = 31;
const double EPS = 1e-6;
long long int N, M, T;
long long int S[MAXN], D[MAXN];
long long int ltn = 0;
long long int lt[MAXN];
int id[MAXN], num[MAXN];
char d[20];
bool cmp(int idl, int idr) {
  if (S[idl] != S[idr]) return S[idl] < S[idr];
  return D[idl] == 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%I64d %I64d %I64d", &N, &M, &T);
  for (int i = 0; i < N; i++) {
    scanf("%I64d %s", &S[i], d);
    S[i]--;
    if (!strcmp(d, "R"))
      D[i] = 1;
    else
      D[i] = -1;
    id[i] = i;
  }
  sort(id, id + N, cmp);
  bool flag = false;
  if (D[id[0]] == -1) {
    flag = true;
    for (int i = 0; i < N; i++) {
      S[i] = (M - S[i]) % M;
      D[i] = -D[i];
    }
  }
  long long int ds = S[id[0]];
  long long int __shift = ds;
  for (int i = 0; i < N; i++) {
    S[i] = (S[i] + M - ds) % M;
  }
  sort(id, id + N, cmp);
  for (int i = 0; i < N; i++) {
    num[id[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    if (D[id[i]] < 0) {
      lt[ltn++] = S[id[i]];
    }
  }
  for (int i = 0; i < ltn; i++) {
    lt[ltn + i] = lt[i] + M;
  }
  long long int shift = (((T / M) % N) * 2 * ltn) % N;
  long long int dtime = T % M;
  for (long long int i = 0; i < 2 * ltn; i++) {
    if (lt[i] < S[id[0]] + 2 * dtime) shift++;
  }
  shift %= N;
  T %= M;
  for (int i = 0; i < N; i++) {
    if (D[i] > 0)
      S[i] = (S[i] + T) % M;
    else
      S[i] = (S[i] + (M - 1) * T) % M;
  }
  long long int ptrs = S[id[0]], ptrd = D[id[0]], ptr = -1;
  sort(id, id + N, cmp);
  for (int i = 0; i < N; i++) {
    if (S[id[i]] == ptrs && D[id[i]] == ptrd) {
      ptr = i;
      break;
    }
  }
  assert(ptr != -1);
  shift = (ptr + N - shift) % N;
  for (int i = 0; i < N; i++) {
    S[i] = (__shift + S[i]);
    if (flag) S[i] = (M - S[i]) % M;
  }
  for (int i = 0; i < N; i++) {
    if (!flag)
      printf("%I64d ", S[id[(num[i] + shift) % N]] + 1);
    else
      printf("%I64d ", S[id[(num[i] + shift) % N]] + 1);
  }
  return 0;
}
