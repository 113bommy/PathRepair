#include <bits/stdc++.h>
using namespace std;
long long C[2626][2626];
void pre() {
  for (int i = 0; i < 2626; i++)
    for (int j = 0; j < 2626; j++) C[i][j] = 0;
  for (int i = 0; i < 2626; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = ((C[i - 1][j - 1] + C[i - 1][j]) % 1000000007);
  }
}
inline long long urns(int n, int k) { return C[n + k - 1][k - 1]; }
inline long long solve(int total, int num) {
  long long all = urns(total, num);
  long long bad = 0;
  for (int i = 1; i <= num; i++) {
    if (total - 26 * i >= 0)
      bad = ((bad +
              ((i % 2) ? 1 : -1) *
                  ((C[num][i] * urns(total - 26 * i, num)) % 1000000007) +
              1000000007) %
             1000000007);
  }
  bad = ((bad) % 1000000007);
  return ((all - bad + 2 * 1000000007 - 1) % 1000000007);
}
int main2() {
  string S;
  cin >> S;
  int size = S.size();
  int total = 0;
  for (int i = 0; i < size; i++) total += (S[i] - 'a');
  cout << solve(total, size) << '\n';
  return 0;
}
int main() {
  pre();
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) main2();
  return 0;
}
