#include <bits/stdc++.h>
using namespace std;
vector<long long> v[200001];
struct AA {
  long long a, b;
} A[200001];
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &A[i].a);
    scanf("%lld", &A[i].b);
    for (long long j = 1; j * j <= A[i].a; j++) {
      if (A[i].a % j == 0) {
        long long x = A[i].a / j;
        v[j].push_back(i);
        if (x == j) continue;
        v[x].push_back(i);
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    long long a, b;
    a = A[i].a;
    b = A[i].b;
    long long l = i - b;
    long long r = i - 1;
    long long ans = 0;
    for (long long j = 1; j * j <= a; j++) {
      if (a % j == 0) {
        long long c = lower_bound(v[j].begin(), v[j].end(), l) - v[j].begin();
        if (c == v[j].size()) {
          ans++;
        } else if (v[j][c] > r) {
          ans++;
        }
        long long x = a / j;
        if (x == j) {
          continue;
        }
        long long cc = lower_bound(v[x].begin(), v[x].end(), l) - v[x].begin();
        if (cc == v[x].size()) {
          ans++;
        } else if (v[x][cc] > r) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}
