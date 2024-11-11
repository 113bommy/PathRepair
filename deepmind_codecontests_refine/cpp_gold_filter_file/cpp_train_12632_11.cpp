#include <bits/stdc++.h>
using namespace std;
void impr(vector<long long> C) {
  printf("%lld", C.back());
  for (int i = C.size() - 2; i >= 0; i--) printf("%05lld", C[i]);
  printf("\n");
}
vector<long long> operator*(vector<long long> a, vector<long long> b) {
  int m = a.size(), n = b.size();
  vector<long long> c(m + n);
  long long s = 0;
  for (int i = 0; i < m + n; i++) {
    int ini = max(0, i - n + 1);
    int fin = min(i + 1, m);
    for (int j = ini; j < fin; j++) s += a[j] * b[i - j];
    int k = i;
    while (s) {
      c[k] += s % 100000;
      s = s / 100000;
      if (c[k] >= 100000) {
        c[k] -= 100000;
        c[k + 1]++;
      }
      k++;
    }
  }
  if (c.back() == 0) c.pop_back();
  return c;
}
vector<long long> operator+(vector<long long> a, vector<long long> b) {
  int m = a.size(), n = b.size();
  if (m < n) swap(a, b), swap(m, n);
  vector<long long> c(m + 1);
  for (int i = 0; i < m; i++) {
    long long s = a[i];
    if (i < n) s += b[i];
    if (c[i] + s >= 100000) c[i + 1]++, s -= 100000;
    c[i] += s;
  }
  if (c.back() == 0) c.pop_back();
  return c;
}
bool operator<(vector<long long> A, vector<long long> B) {
  int m = A.size(), n = B.size();
  if (m < n) return 1;
  if (m > n) return 0;
  for (int i = m - 1; i >= 0; i--) {
    if (A[i] < B[i]) return 1;
    if (A[i] > B[i]) return 0;
  }
  return 0;
}
vector<long long> memo[5001];
vector<long long> pot[2001];
pair<int, int> A[5001];
vector<long long> dp(int pos) {
  if (pos == 0) return vector<long long>(1, 0);
  vector<long long> &res = memo[pos];
  if (res != vector<long long>(1, -1)) return res;
  vector<long long> mx = dp(pos - 1);
  if (A[pos].second == 1) return res = mx;
  for (int i = 0; i < pos; i++)
    if (A[i].second == 1 && A[i].first == A[pos].first) {
      if (mx < dp(i) + pot[A[pos].first]) mx = dp(i) + pot[A[pos].first];
    }
  return res = mx;
}
int main() {
  vector<long long> dos(1, 2);
  pot[0] = vector<long long>(1, 1);
  for (int i = 1; i < 2001; i++) pot[i] = pot[i - 1] * dos;
  int n, k;
  string cad;
  cin >> n;
  for (int i = 0; i < n; i++) memo[i] = vector<long long>(1, -1);
  for (int i = 0; i < n; i++) {
    cin >> cad >> k;
    A[i].first = k;
    A[i].second = (cad == "win" ? 1 : 0);
  }
  impr(dp(n - 1));
}
