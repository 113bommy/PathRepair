#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 60);
int N, M;
long long D[200002], A[200002], B[200002];
long long H[200002];
long long val[4 * 200002], maxA[4 * 200002], maxB[4 * 200002];
int A1, A2, B1, B2;
long long Ar, Br;
void update(int nod, int i1, int i2) {
  if (i1 == i2) {
    val[nod] = -INF;
    maxA[nod] = A[i1];
    maxB[nod] = B[i1];
    return;
  }
  int mid = (i1 + i2) / 2;
  update(nod * 2, i1, mid);
  update(nod * 2 + 1, mid + 1, i2);
  maxA[nod] = max(maxA[nod * 2], maxA[nod * 2 + 1]);
  maxB[nod] = max(maxB[nod * 2], maxB[nod * 2 + 1]);
  val[nod] = max(val[nod * 2], val[nod * 2 + 1]);
  val[nod] = max(val[nod], maxA[nod * 2] + maxB[nod * 2 + 1]);
}
void querymax(int nod, int i1, int i2) {
  if (A1 <= i1 && i2 <= A2) {
    Br = max(Br, maxB[nod]);
    return;
  }
  int mid = (i1 + i2) / 2;
  if (B1 <= mid) querymax(nod * 2, i1, mid);
  if (B2 > mid) querymax(nod * 2 + 1, mid + 1, i2);
}
void query(int nod, int i1, int i2) {
  if (A1 <= i1 && i2 <= A2) {
    Ar = max(Ar, val[nod]);
    B1 = i2 + 1;
    B2 = A2;
    Br = -INF;
    if (B1 <= B2) querymax(1, 1, 2 * N);
    Ar = max(Ar, maxA[nod] + Br);
    return;
  }
  int mid = (i1 + i2) / 2;
  if (A1 <= mid) query(nod * 2, i1, mid);
  if (A2 > mid) query(nod * 2 + 1, mid + 1, i2);
}
int main() {
  cin.sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> D[i + 1];
  for (int i = 1; i <= N; ++i) {
    cin >> H[i];
    H[i] *= 2;
  }
  for (int i = N + 1; i < 2 * N; ++i) {
    D[i + 1] = D[i + 1 - N];
    H[i] = H[i - N];
  }
  H[2 * N] = H[N];
  for (int i = 1; i <= 2 * N; ++i) D[i] += D[i - 1];
  for (int i = 1; i <= 2 * N; ++i) {
    B[i] = H[i] + D[i];
    A[i] = H[i] - D[i];
  }
  update(1, 1, 2 * N);
  for (int i = 1, nod1, nod2; i <= M; ++i) {
    cin >> nod1 >> nod2;
    if (nod1 <= nod2) {
      A1 = nod2 + 1;
      A2 = N + nod1 - 1;
    } else {
      A1 = nod2 + 1;
      A2 = nod1 - 1;
    }
    Ar = -INF;
    query(1, 1, 2 * N);
    cout << Ar << '\n';
  }
}
