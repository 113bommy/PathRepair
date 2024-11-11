#include <bits/stdc++.h>
using namespace std;
long long ans[101];
void pre() {
  set<long long> s;
  for (long long i = 1; i <= 100; i++) {
    s.insert(0);
    for (long long f1 = 0; f1 <= i; f1++) {
      for (long long f2 = 0; f1 + f2 <= i; f2++) {
        s.insert(4 * f1 + 9 * f2 + 49 * (i - f1 - f2));
      }
    }
    ans[i] = s.size();
  }
}
int main() {
  pre();
  long long n;
  cin >> n;
  cout << (n <= 100 ? ans[n] : ans[100] + 49ll * (n - 100)) << '\n';
  return 0;
}
