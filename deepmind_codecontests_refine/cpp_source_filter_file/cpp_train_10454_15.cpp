#include <bits/stdc++.h>
using namespace std;
long long K, X, M, N;
string sA, sB;
int px, py;
bool found[57];
long long b[57], e[57], cnt1[57], cnt2[57], cnt12[57], cnt21[57], cnt11[57],
    cnt22[57];
void rec(int k) {
  if (found[k]) return;
  if (k <= 2) return;
  rec(k - 1);
  rec(k - 2);
  b[k] = b[k - 2];
  e[k] = e[k - 1];
  cnt1[k] = cnt1[k - 1] + cnt1[k - 2];
  cnt2[k] = cnt2[k - 1] + cnt2[k - 2];
  cnt12[k] = cnt12[k - 1] + cnt12[k - 2];
  cnt21[k] = cnt21[k - 1] + cnt21[k - 2];
  cnt11[k] = cnt11[k - 1] + cnt11[k - 2];
  cnt22[k] = cnt22[k - 1] + cnt22[k - 2];
  if (e[k - 2] == 1 && b[k - 1] == 1) cnt11[k]++;
  if (e[k - 2] == 1 && b[k - 1] == 2) cnt12[k]++;
  if (e[k - 2] == 2 && b[k - 1] == 1) cnt21[k]++;
  if (e[k - 2] == 2 && b[k - 1] == 2) cnt22[k]++;
  found[k] = true;
}
bool testx(int n, int m, long long x) {
  if (n < 0 || m < 0 || x < 0) return false;
  for (int i = (0); i < (n / 2 + 1); i++) {
    for (int j = (0); j < (m / 2 + 1); j++) {
      if (cnt1[K] * i + cnt2[K] * j == x) {
        px = i;
        py = j;
        return true;
      }
    }
  }
  return false;
}
bool test() {
  if (testx(N, M, X)) {
    for (int i = (0); i < (px); i++) {
      sA[2 * i] = 'A';
      sA[2 * i + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i] = 'A';
      sB[2 * i + 1] = 'C';
    }
    return true;
  }
  if (testx(N, M - 2, X - cnt22[K])) {
    sB[0] = 'C';
    sB[M - 1] = 'A';
    for (int i = (0); i < (px); i++) {
      sA[2 * i] = 'A';
      sA[2 * i + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i] = 'A';
      sB[2 * i + 1] = 'C';
    }
    return true;
  }
  if (testx(N - 1, M - 1, X - cnt12[K])) {
    sA[N - 1] = 'A';
    sB[0] = 'C';
    for (int i = (0); i < (px); i++) {
      sA[2 * i] = 'A';
      sA[2 * i + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i + 1] = 'A';
      sB[2 * i + 1 + 1] = 'C';
    }
    return true;
  }
  if (testx(N - 1, M - 2, X - cnt22[K] - cnt12[K])) {
    sA[N - 1] = 'A';
    sB[M - 1] = 'A';
    sB[0] = 'C';
    for (int i = (0); i < (px); i++) {
      sA[2 * i] = 'A';
      sA[2 * i + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i + 1] = 'A';
      sB[2 * i + 1 + 1] = 'C';
    }
    return true;
  }
  if (testx(N - 1, M - 1, X - cnt21[K])) {
    sB[M - 1] = 'A';
    sA[0] = 'C';
    for (int i = (0); i < (px); i++) {
      sA[2 * i + 1] = 'A';
      sA[2 * i + 1 + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i] = 'A';
      sB[2 * i + 1] = 'C';
    }
    return true;
  }
  if (testx(N - 1, M - 2, X - cnt22[K] - cnt21[K])) {
    sB[M - 1] = 'A';
    sA[0] = 'C';
    sB[0] = 'C';
    for (int i = (0); i < (px); i++) {
      sA[2 * i + 1] = 'A';
      sA[2 * i + 1 + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i + 1] = 'A';
      sB[2 * i + 1 + 1] = 'C';
    }
    return true;
  }
  if (testx(N - 2, M, X - cnt11[K])) {
    sA[N - 1] = 'A';
    sA[0] = 'C';
    for (int i = (0); i < (px); i++) {
      sA[2 * i + 1] = 'A';
      sA[2 * i + 1 + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i] = 'A';
      sB[2 * i + 1] = 'C';
    }
    return true;
  }
  if (testx(N - 2, M - 1, X - cnt21[K] - cnt11[K])) {
    sA[N - 1] = 'A';
    sB[M - 1] = 'A';
    sA[0] = 'C';
    for (int i = (0); i < (px); i++) {
      sA[2 * i + 1] = 'A';
      sA[2 * i + 1 + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i] = 'A';
      sB[2 * i + 1] = 'C';
    }
    return true;
  }
  if (testx(N - 2, M - 1, X - cnt11[K] - cnt12[K])) {
    sA[N - 1] = 'A';
    sA[0] = 'C';
    sB[0] = 'C';
    for (int i = (0); i < (px); i++) {
      sA[2 * i + 1] = 'A';
      sA[2 * i + 1 + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i + 1] = 'A';
      sB[2 * i + 1 + 1] = 'C';
    }
    return true;
  }
  if (testx(N - 2, M - 2, X - cnt22[K] - cnt12[K] - cnt21[K] - cnt11[K])) {
    sB[M - 1] = 'A';
    sA[0] = 'C';
    sB[0] = 'C';
    sA[N - 1] = 'A';
    for (int i = (0); i < (px); i++) {
      sA[2 * i] = 'A';
      sA[2 * i + 1] = 'C';
    }
    for (int i = (0); i < (py); i++) {
      sB[2 * i + 1] = 'A';
      sB[2 * i + 1 + 1] = 'C';
    }
    return true;
  }
  return false;
}
int main() {
  cin >> K >> X >> N >> M;
  memset((found), (false), sizeof((found)));
  b[1] = 1;
  e[1] = 1;
  cnt1[1] = 1;
  cnt2[1] = 0;
  cnt12[1] = 0;
  cnt21[1] = 0;
  cnt11[1] = 0;
  cnt22[1] = 0;
  b[2] = 2;
  e[2] = 2;
  cnt1[2] = 0;
  cnt2[2] = 1;
  cnt12[2] = 0;
  cnt21[2] = 0;
  cnt11[2] = 0;
  cnt22[2] = 0;
  sA = "";
  sB = "";
  for (int i = (0); i < (N); i++) sA += "X";
  for (int i = (0); i < (M); i++) sB += "X";
  rec(K);
  if (test())
    cout << sA << endl << sB << endl;
  else
    cout << "Happy new year!" << endl;
  return 0;
}
