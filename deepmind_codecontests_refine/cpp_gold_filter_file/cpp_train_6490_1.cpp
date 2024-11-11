#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265358979323846;
long long mod = 1000000000 + 7;
const int N = 1e5 + 5;
vector<bool> prime(N, true);
bool Rev(long long a, long long b) { return (a > b); }
void solve() {
  long long n, m;
  cin >> n >> m;
  if (m == 1) {
    long long i;
    for (long long i = 0; i < n; i += 1) cout << 1 << "\n";
    return;
  }
  if (m & 1) {
    long long mid = (m + 1) / 2;
    long long i;
    long long flag = 1, f = 1;
    long long k = 1;
    for (long long i = 1; i < n + 1; i += 1) {
      if (flag) {
        cout << mid << "\n";
        flag = 0;
      } else {
        cout << mid - k << "\n";
        if (i < n) {
          cout << mid + k << "\n";
          i++;
        }
        if (mid + k == m) {
          flag = 1;
          k = 1;
        } else
          k++;
      }
    }
  } else {
    long long mid = (m + 1) / 2;
    long long i;
    long long k = 0;
    for (long long i = 0; i < n; i += 1) {
      cout << mid - k << "\n";
      if (i < n - 1) {
        cout << mid + k + 1 << "\n";
        i++;
      }
      if (mid + k + 1 == m) {
        k = 0;
      } else
        k++;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  solve();
}
