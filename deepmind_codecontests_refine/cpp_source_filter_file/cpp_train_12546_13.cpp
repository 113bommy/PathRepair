#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long sum = 0, tmp, m = 1000000001;
  int i;
  int k = 0;
  cin >> n;
  while (n--) {
    cin >> tmp;
    sum += tmp;
    if (tmp % 2 == 1) {
      k++;
      if (m > tmp) m = tmp;
    }
  }
  if (k % 2 == 1) sum -= tmp;
  cout << sum << endl;
  return 0;
}
