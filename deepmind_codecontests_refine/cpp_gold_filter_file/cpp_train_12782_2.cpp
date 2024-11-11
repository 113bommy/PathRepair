#include <bits/stdc++.h>
using namespace std;

long f(long n) {
  return n * (n - 1) / 2;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> MA;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    MA[A.at(i)]++;
  }
  long ans = 0;
  for (auto [a, b] : MA) ans += f(b);
  for (auto a : A) cout << ans - f(MA[a]) + f(MA[a] - 1) << "\n";
}