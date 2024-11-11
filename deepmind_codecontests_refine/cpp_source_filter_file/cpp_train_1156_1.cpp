#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
vector<long long> w;
void pd(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      n /= i;
      long long cnt = 1;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      w.push_back(cnt);
    }
  }
  if (n != 1) {
    v.push_back(n);
    w.push_back(1);
  }
}
bool sam() {
  long long t = w[0];
  for (long long i = 1; i <= w.size() - 1; i++) {
    if (w[i] != t) return 0;
  }
  return 1;
}
int main() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 0 << endl;
    return 0;
  }
  pd(n);
  long long ans1 = 1;
  for (long long i = 0; i <= w.size() - 1; i++) {
    ans1 *= v[i];
  }
  cout << ans1 << " ";
  long long max_d = 1;
  for (long long i = 0; i <= w.size() - 1; i++) {
    max_d = max(max_d, w[i]);
  }
  long long ans2 = 0;
  while ((1 << ans2) < max_d) {
    ans2++;
  }
  if ((1 << max_d) < max_d) {
    ans2++;
  } else if (!sam()) {
    ans2++;
  }
  cout << ans2 << endl;
}
