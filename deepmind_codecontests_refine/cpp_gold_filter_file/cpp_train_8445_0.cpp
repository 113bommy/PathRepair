#include <bits/stdc++.h>
using namespace std;
long long k, l1, l2, r1, r2;
vector<long long> lucky_numbers, q[2];
void go(long long tam, long long num) {
  if (tam == 11) return;
  num *= 10;
  lucky_numbers.push_back(num + 4);
  lucky_numbers.push_back(num + 7);
  go(tam + 1, num + 4), go(tam + 1, num + 7);
}
long long Intersection(long long l1, long long r1, long long l2, long long r2) {
  return max(min(r1, r2) - max(l1, l2) + 1, 0LL);
}
int main() {
  cout << setprecision(15) << fixed;
  go(0, 0);
  lucky_numbers.push_back(0);
  sort(lucky_numbers.begin(), lucky_numbers.end());
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  long long a, b, want = 0;
  for (int i = 0, j; i < (int)lucky_numbers.size() - k; ++i) {
    j = i + k;
    a = Intersection(lucky_numbers[i - 1] + 1, lucky_numbers[i], l1, r1);
    b = Intersection(lucky_numbers[j - 1], lucky_numbers[j] - 1, l2, r2);
    want += a * b;
    a = Intersection(lucky_numbers[i - 1] + 1, lucky_numbers[i], l2, r2);
    b = Intersection(lucky_numbers[j - 1], lucky_numbers[j] - 1, l1, r1);
    want += a * b;
    if (k == 1 && l1 <= lucky_numbers[i] && r1 >= lucky_numbers[i] &&
        l2 <= lucky_numbers[i] && r2 >= lucky_numbers[i])
      want--;
  }
  cout << want / (double)((r2 - l2 + 1) * (r1 - l1 + 1)) << endl;
  return 0;
}
