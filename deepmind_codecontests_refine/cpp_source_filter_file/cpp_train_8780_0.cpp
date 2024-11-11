#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000009;
const long long P = 1000000007;
vector<long long> T1, T2;
int l, size;
void Stworz(vector<long long>& T, int n) {
  int p = 1;
  while (p < n) p *= 2;
  l = p;
  size = 2 * p - 1;
  for (int i = 0; i <= size; ++i) T.push_back(0);
}
void Ustaw(vector<long long>& T, int a, long long x) {
  a += l;
  T[a] = x;
  a /= 2;
  while (a != 0) {
    T[a] = (T[2 * a] + T[2 * a + 1]) % MOD;
    a /= 2;
  }
}
long long Suma(vector<long long>& T, int a, int b) {
  if (a > b) return 0;
  a += l;
  b += l;
  long long s = T[a];
  if (a != b) s = (s + T[b]) % MOD;
  while (a / 2 != b / 2) {
    if (a % 2 == 0) s = (s + T[a + 1]) % MOD;
    if (b % 2 == 1) s = (s + T[b - 1]) % MOD;
    a /= 2;
    b /= 2;
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> m >> n;
  vector<long long> gdzieA(n), gdzieB(m);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    gdzieB[x] = i;
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    gdzieA[x] = i;
  }
  vector<long long> pot(n);
  pot[0] = 1;
  for (int i = 1; i < n; ++i) pot[i] = (pot[i - 1] * P) % MOD;
  long long hB = 0;
  for (int i = 0; i < m; ++i) hB = (hB + gdzieB[i] * pot[i]) % MOD;
  Stworz(T1, n);
  Stworz(T2, n);
  int odp = 0;
  long long hA = 0;
  for (int i = 0; i < m; ++i) {
    hA = (hA + Suma(T1, 0, gdzieA[i]) * pot[i]) % MOD;
    hA = (hA + Suma(T2, gdzieA[i], n - 1)) % MOD;
    Ustaw(T1, gdzieA[i], 1);
    Ustaw(T2, gdzieA[i], pot[i]);
  }
  if (hA == hB) ++odp;
  for (int i = 1; i + m - 1 < n; ++i) {
    int j = i + m - 1;
    hA = (hA + Suma(T1, 0, gdzieA[j]) * pot[j]) % MOD;
    hA = (hA + Suma(T2, gdzieA[j], n - 1)) % MOD;
    Ustaw(T1, gdzieA[j], 1);
    Ustaw(T2, gdzieA[j], pot[j]);
    hA = (hA - Suma(T1, 0, gdzieA[i - 1] - 1) * pot[i - 1]) % MOD;
    if (hA < 0) hA += MOD;
    hA = (hA - Suma(T2, gdzieA[i - 1] + 1, n - 1)) % MOD;
    if (hA < 0) hA += MOD;
    Ustaw(T1, gdzieA[i - 1], 0);
    Ustaw(T2, gdzieA[i - 1], 0);
    hB = (hB * P) % MOD;
    if (hA == hB) ++odp;
  }
  cout << odp;
  return 0;
}
