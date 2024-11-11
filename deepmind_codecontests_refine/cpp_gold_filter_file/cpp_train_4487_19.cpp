#include <bits/stdc++.h>
using namespace std;
template <typename T>
void alert(const T& t) {
  cout << t;
  exit(0);
}
template <typename T>
inline void alert(vector<T>& t, char delim = ' ') {
  for (T const& ti : t) cout << ti << delim;
  exit(0);
}
int gcd(int a, int b) {
  if (a > b) swap(a, b);
  while (a > 0) {
    b = b % a;
    swap(a, b);
  }
  return b;
}
int main() {
  {
    if ("TASKNAME" != "TASKNAME") {
      freopen(
          "TASKNAME"
          ".in",
          "r", stdin);
      freopen(
          "TASKNAME"
          ".out",
          "w", stdout);
    } else if ("TASKNAME" == "1") {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    }
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> vec(n * 2);
  for (long long i = 0; i < n * 2; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  long long a = vec[n - 1] - vec[0], b = vec.back() - vec[n];
  long long mi = a * b;
  for (long long i = 1; i < n; i++) {
    a = vec[i + n - 1] - vec[i];
    b = vec.back() - vec[0];
    mi = min(mi, a * b);
  }
  cout << mi;
  return 0;
}
