#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, i, j, len;
  char s[1000006], flag = '0';
  scanf("%s", s);
  cin >> a >> b;
  len = strlen(s);
  long long int *mod_10 =
      (long long int *)malloc(sizeof(long long int) * 1000006);
  long long int *mod_a =
      (long long int *)malloc(sizeof(long long int) * 1000006);
  long long int *mod_b =
      (long long int *)malloc(sizeof(long long int) * 1000006);
  if (len == 1)
    cout << "NO" << endl;
  else {
    mod_10[0] = 1;
    for (i = 1; i < len; i++) mod_10[i] = (10 * mod_10[i - 1]) % b;
    mod_a[0] = (s[0] - '0') % a;
    mod_b[len - 1] = (s[len - 1] - '0') % b;
    for (i = 1; i < len; i++) {
      mod_a[i] = (mod_a[i - 1] * 10 + s[i] - '0') % a;
      mod_b[len - i - 1] =
          (mod_10[i] * (s[len - i - 1] - '0') + mod_b[len - i]) % b;
    }
    if (s[0] != '0' && mod_a[0] == 0 && s[1] != 0 && mod_b[1] == 0) {
      flag = '1';
      cout << "YES" << endl;
      cout << s[0] << endl;
      for (i = 1; i < len; i++) cout << s[i];
      cout << endl;
    }
    for (i = 1; i < len - 1 && flag == '0'; i++) {
      if (mod_a[i] == 0 && s[i + 1] != '0' && mod_b[i + 1] == 0) {
        cout << "YES" << endl;
        for (j = 0; j <= i; j++) cout << s[j];
        cout << endl;
        for (j = i + 1; j < len; j++) cout << s[j];
        cout << endl;
        flag = '1';
      }
    }
    if (flag == '0') cout << "NO" << endl;
  }
  return 0;
}
