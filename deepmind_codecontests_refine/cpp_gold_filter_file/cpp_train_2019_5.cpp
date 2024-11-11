#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  long long first = 0, second = 0;
  long long tmp, cou = n, take = 1;
  cin >> tmp;
  second += (n - 2);
  for (int i = 0; i < n - 1; i++) {
    long long tmp1;
    cin >> tmp1;
    long long d = first - second * tmp1;
    if (d >= k) {
      take++;
      first += tmp1 * (take - 1);
      second = (cou - take - 1) * take;
    } else {
      cou--;
      second -= take;
      cout << i + 2 << endl;
    }
  }
  return 0;
}
