#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, len = 0, cnt = 0, num = 0, hate = 0, num_v = 0, num_k = 0;
  char str[110];
  cin >> str;
  len = strlen(str);
  for (i = 0; i < len - 1; i++) {
    if (str[i] == 'V' && str[i + 1] == 'K') {
      cnt++;
      str[i] = '0';
      str[i + 1] = '0';
    }
  }
  for (i = 0; i < len - 1; i++) {
    if (str[i] == 'V' && str[i + 1] == 'V') {
      num_v++;
      num_k = 0;
    } else if (str[i] == 'K' && str[i + 1] == 'K') {
      num_k++;
      num_v = 0;
    }
    if (num_v == 2) {
      cnt++;
      break;
    } else if (num_k == 2) {
      cnt++;
      break;
    }
  }
  cout << cnt << endl;
  return 0;
}
