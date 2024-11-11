#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum, limit;
  cin >> sum >> limit;
  int lowbit_limit[limit + 1];
  lowbit_limit[0] = 0;
  for (int j = 1; j <= limit; j++) {
    int pos = 0;
    int digit = j;
    while ((digit & 1) == 0) {
      pos += 1;
      digit >>= 1;
    }
    int num = pow(2, pos);
    lowbit_limit[j] = num;
  }
  vector<int> set_digits;
  int size_set = 0;
  int curr_sum = 0;
  for (int i = limit; i >= 1; i--) {
    if (curr_sum + lowbit_limit[i] <= sum) {
      size_set++;
      curr_sum += lowbit_limit[i];
      set_digits.push_back(i);
    }
    if (curr_sum == sum) break;
  }
  if (curr_sum == sum) {
    cout << size_set << endl;
    for (auto x : set_digits) cout << x << " ";
    cout << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
