#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long a, b;
  cin >> a >> b;
  long long cur = 0, rem = 0;
  set<long long> first_day, second_day;
  for (long long i = 1; i <= a; ++i) {
    long long sum = (i * (i + 1)) / 2;
    first_day.insert(i);
    cur = i;
    if (sum == a) break;
    if (sum > a) {
      rem = sum - a;
      first_day.erase(rem);
      break;
    }
  }
  long long sum2 = rem;
  if (rem && rem <= b) second_day.insert(rem);
  for (long long j = cur + 1; j <= b; ++j) {
    if (sum2 + j > b) break;
    sum2 += j;
    second_day.insert(j);
  }
  cout << first_day.size() << "\n";
  for (long long x : first_day) cout << x << " ";
  cout << "\n" << second_day.size() << "\n";
  for (long long x : second_day) cout << x << " ";
  return 0;
}
