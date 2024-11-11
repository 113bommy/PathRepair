#include <bits/stdc++.h>
using namespace std;
char x[100010];
char a[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
int main() {
  cin >> x;
  int l = strlen(x);
  int flag = 1;
  for (int i = 0; i < l / 2; i++)
    if (x[i] != x[l - i - 1]) {
      flag = 0;
      break;
    } else {
      flag = 0;
      for (int j = 0; j < 11; j++)
        if (x[i] == a[j]) {
          flag = 1;
          break;
        }
      if (!flag) break;
    }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
