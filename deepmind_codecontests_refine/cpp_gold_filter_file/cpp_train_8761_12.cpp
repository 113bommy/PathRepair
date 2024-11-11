#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  scanf("%d%d", &n, &k);
  string str;
  cin >> str;
  int num1, num0;
  num0 = num1 = -1;
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == '0') {
      if (-1 == num0) num0 = i;
      num1 = i;
    }
  }
  int num_0, num_1;
  num_0 = num_1 = -1;
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == '1') {
      if (-1 == num_0) num_0 = i;
      num_1 = i;
    }
  }
  if (num1 - num0 < k || num_1 - num_0 < k) {
    puts("tokitsukaze");
  } else if (num0 - num1 > k || num0 >= k || num1 < n - k ||
             num_1 - num_0 > k || num_0 >= k || num_1 < n - k) {
    puts("once again");
  } else
    puts("quailty");
  return 0;
}
