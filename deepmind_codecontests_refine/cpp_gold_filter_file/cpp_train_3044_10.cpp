#include <bits/stdc++.h>
const long long INF = 1e9 + 7;
using namespace std;
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    vector<pair<long long, long long> > ba(n);
    vector<long long> z(n);
    long long minNum = 1e15;
    for (long long i = 0; i < n; i++) {
      long long prev = (i - 1);
      if (prev < 0) {
        prev += n;
      }
      ba[i].first = a[i];
      ba[i].second = max(a[i] - b[prev], 0LL);
      z[i] = ba[i].first - ba[i].second;
      minNum = min(z[i], minNum);
    }
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      sum += ba[i].second;
    }
    cout << sum + minNum << endl;
  }
  return 0;
}
