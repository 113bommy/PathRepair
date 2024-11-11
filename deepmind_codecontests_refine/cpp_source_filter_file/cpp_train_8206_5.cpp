#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long> A(N + 1);
  for (int i = 1, a; i <= N && cin >> a; i++) A.at(i) = A.at(i - 1) + a;
  long long ans = LLONG_MAX;
  for (int i = 1; i <= N; i++) ans = min(ans, abs(A.at(N) - A.at(i) * 2));
  cout << ans << "\n";
}
