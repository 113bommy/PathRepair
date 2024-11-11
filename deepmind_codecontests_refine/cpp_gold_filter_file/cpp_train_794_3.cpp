#include <bits/stdc++.h>
using namespace std;
int N;
int g[1 << 19];
complex<double> a[1 << 19], b[1 << 19];
int mod = 1009;
void FFTinit(int k) {
  for (int i = 1; i < N; i++) g[i] = g[i >> 1] >> 1 | ((i & 1) << k);
}
void FFT(complex<double> *a, int f) {
  int i, j, k, p;
  for (i = 0; i < N; i++)
    if (g[i] > i) swap(a[i], a[g[i]]);
  for (i = 1; i < N; i <<= 1) {
    complex<double> e(cos(acos(-1) / i), f * sin(acos(-1) / i));
    for (j = 0; j < N; j += i << 1) {
      complex<double> w(1, 0);
      for (k = 0; k < i; k++, w *= e) {
        complex<double> first = a[j + k], second = w * a[j + k + i];
        a[j + k] = first + second;
        a[j + k + i] = first - second;
      }
    }
  }
}
vector<int> multi(vector<int> first, vector<int> second) {
  N = first.size() + second.size() - 1;
  for (int cnt = 0, i = 1;; i <<= 1, cnt++) {
    if (i >= N) {
      N = i;
      FFTinit(cnt - 1);
      break;
    }
  }
  for (int i = 0; i < N; i++) a[i] = 0;
  for (int i = 0; i < N; i++) b[i] = 0;
  for (int i = 0; i < first.size(); i++) a[i] = first[i];
  for (int i = 0; i < second.size(); i++) b[i] = second[i];
  FFT(a, 1);
  FFT(b, 1);
  for (int i = 0; i < N; i++) a[i] = a[i] * b[i];
  FFT(a, -1);
  vector<int> ret;
  ret.clear();
  for (int i = 0; i < first.size() + second.size() - 1; i++)
    ret.push_back(((long long)(a[i].real() / N + 0.5) % mod + mod) % mod);
  while (ret.back() == 0) ret.pop_back();
  return ret;
}
bool operator<(const vector<int> &a, const vector<int> &b) {
  return a.size() < b.size();
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int cnt[200005];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
  for (int i = 1; i <= m; i++) {
    if (cnt[i] != 0) {
      vector<int> v;
      for (int j = 0; j <= cnt[i]; j++) v.push_back(1);
      pq.push(v);
    }
  }
  while (pq.size() > 1) {
    vector<int> v1 = pq.top();
    pq.pop();
    vector<int> v2 = pq.top();
    pq.pop();
    vector<int> res = multi(v1, v2);
    pq.push(res);
  }
  printf("%d\n", pq.top()[k]);
}
