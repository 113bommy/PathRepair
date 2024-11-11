#include <bits/stdc++.h>
using namespace std;
char S[100001], T[1000001];
int A[21][1000001];
int n, m;
int s[1000001], nr[1000001], w[1000001], ns[1000001];
void suf_arr() {
  vector<pair<char, int>> V;
  for (int i = 0; i < m; i++) V.push_back({T[i], i});
  sort(V.begin(), V.end());
  int k = 0;
  for (int i = 0; i < m; i++) {
    if (V[i].first != V[k].first) {
      k = i;
    }
    A[0][V[i].second] = k;
    w[k] = 1;
  }
  for (int i = 0; i < m; i++) s[i] = V[i].second;
  for (int h = 1, k = 2; k <= m; k <<= 1, h++) {
    memset(nr, 0, sizeof(nr));
    for (int i = 0; i < m; i++) {
      int e = s[i];
      if (e + k / 2 >= m) {
        int b = A[h - 1][e];
        ns[b + nr[b]] = e;
        w[b + nr[b]] = 1;
        nr[b]++;
      }
    }
    for (int i = 0; i < m; i++) {
      int e = s[i];
      if (e - k / 2 >= 0) {
        int b = A[h - 1][e - k / 2];
        ns[b + nr[b]] = e - k / 2;
        nr[b]++;
      }
    }
    memcpy(s, ns, sizeof(s));
    for (int i = 1; i < m; i++) {
      int e = s[i];
      if (w[i] != 1) {
        int p = s[i - 1];
        if (e + k / 2 >= m || p + k / 2 >= m ||
            A[h - 1][e + k / 2] != A[h - 1][p + k / 2])
          w[i] = 1;
      }
    }
    int u = 0;
    for (int i = 0; i < m; i++) {
      if (w[i]) u = i;
      A[h][s[i]] = u;
    }
  }
}
int lcp(int i, int j) {
  int h = 0;
  for (; (1 << h) <= m; h++)
    ;
  h--;
  int ret = 0;
  for (; h >= 0; h--) {
    if (A[h][i] == A[h][j]) {
      ret += 1 << h;
      i += 1 << h;
      j += 1 << h;
    }
  }
  return ret;
}
int main() {
  scanf("%s ", S);
  scanf("%s ", T);
  n = (int)strlen(S);
  m = (int)strlen(T);
  suf_arr();
  int a, b;
  int na = 0;
  int nb = 0;
  for (int i = 0; i < n; i++) {
    na += S[i] == S[0];
    nb += S[i] != S[0];
  }
  int ret = 0;
  for (int a = 1; a * na <= m; a++) {
    int b = nb > 0 ? (m - a * na) / nb : 0;
    if ((m - a * na) % nb != 0) continue;
    if (nb > 0 && b == 0) continue;
    int p = 0;
    int fa = -1, fb = -1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      bool isa = S[i] == S[0];
      if (isa) {
        if (fa == -1)
          fa = p;
        else {
          if (lcp(p, fa) < a) {
            ok = false;
            break;
          }
        }
      } else {
        if (fb == -1)
          fb = p;
        else {
          if (lcp(p, fb) < b) {
            ok = false;
            break;
          }
        }
      }
      if (S[i] == S[0])
        p += a;
      else
        p += b;
    }
    if (a == b && fa != -1 && fb != -1 && lcp(fa, fb) >= a) ok = false;
    if (ok) ret++;
  }
  printf("%d\n", ret);
  return 0;
}
