#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const int INF = 1e9;
const long long MOD = 1e9 + 7;
const int N = 1e5 + 5, MO = 500, SQ = 320;
int n, q, A[N], QL[N], QR[N], P[N], T[N], C[N], K[N], Q[N];
vector<int> B, X, Y;
bool CMP(int i, int j) {
  if (QL[i] / MO != QL[j] / MO) return QL[i] < QL[j];
  return (QL[i] / MO) % 2 ? QR[i] > QR[j] : QR[i] < QR[j];
}
void Update(int x, int y) { T[C[x]]--, C[x] += y, T[C[x]]++; }
void Insert(int x, int y) {
  if (x >= SQ && !K[x]) Y.push_back(x);
  K[x] += y;
}
int Huf() {
  X.clear(), Y.clear();
  for (int i : B)
    if (C[i] >= SQ) X.push_back(C[i]), K[C[i]]++;
  sort(X.begin(), X.end());
  int huf = 0, c = 0, x = 0, y = 0;
  for (int i = 1; i < SQ; i++)
    if (K[i] + T[i]) {
      K[i] += T[i];
      if (c) huf += i + c, K[i]--, Insert(i + c, 1), c = 0;
      if (K[i] & 1) c = i, K[i]--;
      if (K[i]) huf += i * K[i], Insert(i + i, K[i] >> 1), K[i] = 0;
    }
  while (x < (int)(X.size()) && y < (int)(Y.size())) {
    while (x + 1 < (int)(X.size()) && X[x + 1] == X[x]) x++;
    while (y + 1 < (int)(Y.size()) && Y[y + 1] == Y[y]) y++;
    int i = 0;
    if (x == (int)(X.size()))
      i = Y[y++];
    else if (y == (int)(Y.size()))
      i = X[x++];
    else if (X[x] < Y[y])
      i = X[x++];
    else
      i = Y[y++];
    if (c) huf += i + c, K[i]--, Insert(i + c, 1), c = 0;
    if (K[i] & 1) c = i, K[i]--;
    if (K[i]) huf += i * K[i], Insert(i + i, K[i] >> 1), K[i] = 0;
  }
  return huf;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  mt19937 Rnd(time(0));
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i], C[A[i]]++;
  for (int i = 0; i < N; i++)
    if (C[i] >= SQ) B.push_back(i);
  for (int i = 0; i < n; i++) C[A[i]]--;
  cin >> q;
  for (int i = 0; i < q; i++) cin >> QL[i] >> QR[i], QL[i]--, P[i] = i;
  sort(P, P + q, CMP);
  int L = 0, R = 0;
  for (int i = 0; i < q; i++) {
    int l = QL[P[i]], r = QR[P[i]];
    while (l < L) Update(A[--L], +1);
    while (R < r) Update(A[R++], +1);
    while (L < l) Update(A[L++], -1);
    while (r < R) Update(A[--R], -1);
    Q[P[i]] = Huf();
  }
  for (int i = 0; i < q; i++) cout << Q[i] << endl;
  return 0;
}
