#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, n, a, b, c, m, x, y, z, num,
      count = 0, count1 = 0, count2 = 0, sum = 0, sum1 = 0, sum2 = 0, check = 0,
      len = 0;
  string str, str1, str2;
  cin >> n;
  cin >> str;
  len = str.size();
  int arr[n];
  char ch = 'a';
  memset(arr, 0, sizeof(arr));
  for (i = 0; i < len; i++) {
    if (str[i] != '?') {
      x = str[i] - 97;
      if (arr[x] == 0) count++;
      arr[x]++;
    }
  }
  k = 0;
  for (i = (len + 1) / 2 - 1; i >= 0; i--) {
    j = len - 1 - i;
    if (str[i] == '?' && str[j] != '?') str[i] = str[j];
    if (str[i] != '?' && str[j] == '?') str[j] = str[i];
    if (str[i] != '?' && str[j] != '?' && str[i] != str[j]) {
      check = 1;
      cout << "IMPOSSIBLE";
      break;
    }
    if (str[i] == '?' && str[j] == '?') {
      if (count == n)
        str[i] = str[j] = 'a';
      else {
        while (arr[k] != 0 && k <= n) {
          k++;
        }
        arr[k]++;
        count++;
        str[i] = str[j] = (char)ch + k;
      }
    }
  }
  if (check == 0 && count == n)
    cout << str;
  else if (check == 0)
    cout << "IMPOSSIBLE";
  return 0;
}
