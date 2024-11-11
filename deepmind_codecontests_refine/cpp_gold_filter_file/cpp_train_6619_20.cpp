#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
const long long inf = (long long)1e18;
const long double e = 2.718281828459;
const long double pi = 3.141592653;
using namespace std;
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (T &cnt : arr) {
    in >> cnt;
  }
  return in;
}
void solve() {
  long long n, cnt = 0, answer = 0;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n * 2; i++) {
    long long a;
    cin >> a;
    a--;
    if (arr[a] == 0) {
      cnt++;
      answer = max(answer, cnt);
      arr[a]++;
    } else {
      cnt--;
      arr[a]++;
    }
  }
  cout << answer;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  srand(time(0));
  solve();
  return 0;
}
