#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 123;
long long get_sum(long long i, long long j) {
  cout << "and"
       << " " << i + 1 << " " << j + 1 << endl;
  long long one;
  cin >> one;
  cout << "or"
       << " " << i + 1 << " " << j + 1 << endl;
  long long two;
  cin >> two;
  return one + two;
}
signed main() {
  setlocale(LC_ALL, "rus");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  --k;
  vector<long long> sums(n);
  for (long long i = 1; i < n; ++i) {
    sums[i] = get_sum(0, i);
  }
  long long plus = get_sum(1, 2);
  long long a = sums[2] - plus + sums[1];
  vector<long long> have(n);
  have[0] = a;
  for (long long i = 1; i < n; ++i) {
    have[i] = sums[i] - a;
  }
  sort(have.begin(), have.end());
  cout << "finish"
       << " " << have[k] << endl;
}
