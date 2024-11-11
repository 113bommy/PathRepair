#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 7;
const long double pi = acos(-1);
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  long long int sum_0 = 0, sum_1 = 0, sum_2 = 0;
  for (int i = 0; i < n; i++) {
    long long int e;
    cin >> e;
    sum_0 += e;
  }
  for (int i = 0; i < n - 1; i++) {
    long long int e;
    cin >> e;
    sum_1 += e;
  }
  for (int i = 0; i < n - 2; i++) {
    long long int e;
    cin >> e;
    sum_2 += e;
  }
  cout << sum_0 - sum_1 << endl << sum_1 - sum_2 << endl;
  return 0;
}
