#include <bits/stdc++.h>
using namespace std;
long long Set(long long N, long long pos) { return N = N | (1 << pos); }
long long reset(long long N, long long pos) { return N = N & ~(1 << pos); }
bool check(long long N, long long pos) { return (bool)(N & (1 << pos)); }
void CI(long long &_x) { scanf("%d", &_x); }
void CO(long long &_x) { cout << _x; }
template <typename T>
void getarray(T a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void prLLIarray(T a[], long long n) {
  for (long long i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const long long INF = 0x7f7f7f7f;
long long dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
long long dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
long long dr4[4] = {0, 0, 1, -1};
long long dc4[4] = {-1, 1, 0, 0};
long long kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
vector<long long> V;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long S2 = 0, S1 = 0;
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    V.push_back(temp);
    S1 += temp;
  }
  sort(V.begin(), V.end());
  long long pre = 0;
  for (long long i = 0; i < n; i++) {
    S2 += (1LL * i * V[i]) - pre;
    pre += V[i];
  }
  long long total = S1 + 2 * S2;
  long long gc = gcd(total, n);
  cout << (total / gc) << " " << (n / gc) << "\n";
}
