#include <bits/stdc++.h>
using namespace std;
const int MN = 500010;
int D[MN << 1];
void radixSort(int *A, int *B, int *C, int N, int M) {
  for (int i = 0; i < M; i++) D[i] = 0;
  for (int i = 0; i < N; i++) D[B[A[i]]]++;
  for (int i = 1; i < M; i++) D[i] += D[i - 1];
  for (int i = N - 1; i >= 0; i--) C[--D[B[A[i]]]] = A[i];
}
int T[MN << 1], B[MN << 1];
void suffixArray(string &S, int *C, int N) {
  memset(B, -1, sizeof(B));
  for (int i = 0; i < N; i++) {
    T[i] = i;
    B[i] = S[i];
  }
  radixSort(T, B, C, N, 128);
  for (int i = 1; i < N; i <<= 1) {
    int k = 0;
    for (int j = 0; j < i; j++) T[k++] = N - i + j;
    for (int j = 0; j < N; j++)
      if (C[j] >= i) T[k++] = C[j] - i;
    radixSort(T, B, C, N, max(N, 128));
    T[C[0]] = k = 0;
    for (int j = 1; j < N; j++) {
      if (B[C[j]] != B[C[j - 1]] || B[C[j] + i] != B[C[j - 1] + i]) k++;
      T[C[j]] = k;
    }
    for (int j = 0; j < N; j++) B[j] = T[j];
  }
}
int R[MN];
void LCP(string &S, int *C, int *L, int N) {
  for (int i = 0; i < N; i++) R[C[i]] = i;
  for (int i = 0, h = 0; i < N; i++) {
    if (R[i]) {
      while (i + h < N && C[R[i] - 1] + h < N && S[i + h] == S[C[R[i] - 1] + h])
        h++;
      L[R[i]] = h;
    }
    if (h) h--;
  }
}
struct BIT {
  vector<int> tree;
  void init() { tree = vector<int>(4 * MN, -1e9); }
  void upd(int idx, int val, int l, int r, int n) {
    if (idx < l || r < idx) return;
    if (l == r) {
      tree[n] = val;
      return;
    }
    int m = (l + r) >> 1;
    upd(idx, val, l, m, 2 * n);
    upd(idx, val, m + 1, r, 2 * n + 1);
    tree[n] = max(tree[2 * n], tree[2 * n + 1]);
  }
  int quer(int a, int b, int l, int r, int n) {
    if (b < l || r < a) return -1e9;
    if (a <= l && r <= b) return tree[n];
    int m = (l + r) >> 1;
    int L = quer(a, b, l, m, 2 * n);
    int R = quer(a, b, m + 1, r, 2 * n + 1);
    return max(L, R);
  }
} bit;
int N;
string S;
int sa[MN], lcp[MN], lspt[20][MN], rspt[20][MN], prec[MN], dp[MN];
int lquery(int x, int k) {
  for (int i = 20; i--;) {
    int t = x - (1 << i);
    if (t < -1) continue;
    if (lspt[i][x] < k) continue;
    x = t;
    if (lcp[x + 1] < k) break;
  }
  return x + 1;
}
int rquery(int x, int k) {
  for (int i = 20; i--;) {
    int t = x + (1 << i);
    if (t > N) continue;
    if (rspt[i][x] < k) continue;
    x = t;
    if (lcp[x - 1] < k) break;
  }
  return x - 1;
}
int query(int l, int r) {
  if (l > r) swap(l, r);
  int t = prec[r - l + 1];
  return min(rspt[t][l], lspt[t][r]);
}
bool check(int st, int len) {
  if (len == 0) return true;
  return bit.quer(lquery(st, len), rquery(st, len), 0, MN - 1, 1) >= len;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> N >> S;
  for (int i = 1; i < MN; i++) {
    for (int j = 0; j < 20; j++) {
      if ((1 << j) > i) break;
      prec[i] = j;
    }
  }
  suffixArray(S, sa, N);
  LCP(S, sa, lcp, N);
  for (int i = 0; i < N; i++) {
    lspt[0][i] = N - sa[i];
    rspt[0][i] = N - sa[i];
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < N; j++) {
      int t = j - (1 << (i - 1));
      if (t < -1) continue;
      lspt[i][j] = min((t == -1 ? (int)1e9 : lspt[i - 1][t]),
                       min(lspt[i - 1][j], lcp[t + 1]));
    }
    for (int j = 0; j < N; j++) {
      int t = j + (1 << (i - 1));
      if (t > N) continue;
      rspt[i][j] = min((t == N ? (int)1e9 : rspt[i - 1][t]),
                       min(rspt[i - 1][j], lcp[t]));
    }
  }
  int ans = 1;
  int pos = N;
  bit.init();
  for (int i = N - 1; i >= 0; i--) {
    while (i < pos) {
      if (pos < N) bit.upd(R[pos], dp[pos], 0, MN - 1, 1);
      if (check(R[i], pos - i - 1) || check(R[i + 1], pos - i - 1))
        break;
      else
        pos--;
    }
    dp[i] = pos - i;
    ans = max(ans, dp[i]);
  }
  cout << ans;
}
