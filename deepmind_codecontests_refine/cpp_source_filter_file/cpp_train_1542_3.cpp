#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) cin >> A.at(i);
  int cnt = 0;
  for (int i = N; i > 0; i--) {
    for (int j = i + i; j < N; j += i) A.at(i) ^= A.at(j);
    if (A.at(i)) cnt++;
  }
  cout << cnt << "\n";
  for (int i = 1; i <= N; i++)
    if (A.at(i)) cout << i << "\n";
}
