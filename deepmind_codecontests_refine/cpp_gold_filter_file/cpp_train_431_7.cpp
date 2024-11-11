#include <bits/stdc++.h>
using namespace std;
bool SbS(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long SUMD(long long n);
long long BS(vector<long long> &PS, long long s, long long e, long long ser);
long long MI(long long a, long long m);
bool P[2002LL];
void Sieve(int n = 100005);
int nCrModp(int n, int r, int p);
vector<long long> PF(long long n);
long long Powb(long long b, long long n);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long q = 1;
  cin >> q;
  while (q--) {
    long long n, m, k, i, j, l, r, a, t, b, c, u, v, w, p;
    cin >> n >> m;
    vector<long long> Ind(3 * n + 1);
    vector<long long> M;
    for (i = 1; i <= m; i++) {
      cin >> u >> v;
      if (Ind[u] == 0 and Ind[v] == 0) {
        M.push_back(i);
        Ind[u] = 1;
        Ind[v] = 1;
      }
    }
    if (M.size() >= n) {
      cout << "Matching"
           << "\n";
      for (int i = 0; i < n; i++) {
        cout << M[i] << " ";
      };
      cout << "\n";
    } else {
      cout << "IndSet"
           << "\n";
      for (i = 1, j = 1; i <= 3 * n, j <= n; i++) {
        if (Ind[i] == 0) {
          cout << i << " ";
          j++;
        }
      }
      cout << "\n";
    }
  }
  return 0;
}
long long Powb(long long b, long long n) {
  if (n == 0) return 1LL;
  if (n == 1) return b;
  long long temp = Powb(b, n / 2);
  if (n % 2 == 0) {
    return (temp * temp) % 1000000007;
  } else {
    return (b * ((temp * temp) % 1000000007)) % 1000000007;
  }
}
long long SUMD(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
long long BS(vector<long long> &PS, long long s, long long e, long long ser) {
  if (s > e) return s;
  long long mid = (s + e) / 2;
  if (PS[mid] == ser) {
    return mid;
  } else if (PS[mid] > ser) {
    return BS(PS, s, mid - 1, ser);
  } else
    return BS(PS, mid + 1, e, ser);
}
long long MI(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void Sieve(int n) {
  memset(P, true, sizeof(P));
  P[0] = false;
  P[1] = false;
  for (long long i = 2; i * i <= n; i++) {
    if (P[i]) {
      for (long long j = i * i; j <= n; j += i) {
        P[j] = false;
      }
    }
  }
}
int nCrModp(int n, int r, int p) {
  int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
vector<long long> PF(long long n) {
  vector<long long> pf;
  if (n % 2 == 0) {
    pf.push_back(2LL);
    n = n / 2;
    while (n % 2 == 0) n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    long long flag = 1;
    while (n % i == 0) {
      if (flag) {
        pf.push_back(i);
        flag = 0;
      }
      n = n / i;
    }
  }
  if (n > 2) pf.push_back(n);
  return pf;
}
