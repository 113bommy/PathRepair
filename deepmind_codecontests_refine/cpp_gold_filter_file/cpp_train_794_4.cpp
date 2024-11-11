#include <bits/stdc++.h>
using namespace std;
struct FFT {
  using C = complex<double>;
  const double PI = acos(-1);
  vector<vector<C> > rts, rrts;
  void DFT(vector<C> &F, bool rev) {
    int N = (int)F.size();
    auto &r = rev ? rrts : rts;
    for (int i = 0, j = 1; j + 1 < N; j++) {
      for (int k = N >> 1; k > (i ^= k); k >>= 1)
        ;
      if (i > j) swap(F[i], F[j]);
    }
    if (rts.size() < N) {
      rts.resize(N), rrts.resize(N);
      for (int i = 1; i < N; i <<= 1) {
        if (rts[i].size()) continue;
        rts[i].resize(i), rrts[i].resize(i);
        for (int k = 0; k < i; k++) {
          rts[i][k] = polar(1.0, PI / i * k);
          rrts[i][k] = polar(1.0, -PI / i * k);
        }
      }
    }
    C s, t;
    for (int i = 1; i < N; i <<= 1) {
      for (int j = 0; j < N; j += i * 2) {
        for (int k = 0; k < i; k++) {
          s = F[j + k];
          t = C(F[j + k + i].real() * r[i][k].real() -
                    F[j + k + i].imag() * r[i][k].imag(),
                F[j + k + i].real() * r[i][k].imag() +
                    F[j + k + i].imag() * r[i][k].real());
          F[j + k] = s + t, F[j + k + i] = s - t;
        }
      }
    }
    if (rev)
      for (int i = 0; i < N; i++) F[i] /= N;
  }
  vector<int> Multiply(const vector<int> &A, const vector<int> &B) {
    int sz = 1;
    while (sz < A.size() + B.size() - 1) sz <<= 1;
    vector<C> F(sz), G(sz);
    for (int i = 0; i < A.size(); i++) F[i] = A[i];
    for (int i = 0; i < B.size(); i++) G[i] = B[i];
    DFT(F, false);
    DFT(G, false);
    for (int i = 0; i < sz; i++) F[i] *= G[i];
    DFT(F, true);
    vector<int> res(A.size() + B.size() - 1);
    for (int i = 0; i < A.size() + B.size() - 1; i++)
      res[i] = (long long)(F[i].real() + 0.5) % 1009;
    return res;
  }
};
int main() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  vector<int> cnt(M, 0);
  for (long long i = (long long)(0); i < (long long)(N); i++) {
    int a;
    scanf("%d", &a);
    a--;
    cnt[a]++;
  }
  auto cmp = [](const vector<int> &a, const vector<int> &b) {
    return a.size() > b.size();
  };
  priority_queue<vector<int>, vector<vector<int> >, decltype(cmp)> que(cmp);
  for (long long i = (long long)(0); i < (long long)(M); i++) {
    que.push(vector<int>(cnt[i] + 1, 1));
  }
  FFT fft;
  while (que.size() > 1) {
    auto a = que.top();
    que.pop();
    auto b = que.top();
    que.pop();
    que.push(fft.Multiply(a, b));
  }
  printf("%d\n", que.top()[K]);
  return 0;
}
