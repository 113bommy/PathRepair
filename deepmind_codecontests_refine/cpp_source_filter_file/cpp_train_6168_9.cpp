#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    cin >> s;
    sort(s.begin(), s.end());
    int flag = 1;
    for (int i = 1; i < s.length(); i++)
      if (s[i] != s[i - 1]) flag = 0;
    if (flag == 1) {
      int num = n / k;
      n %= k;
      if (n) num++;
      for (int i = 1; i <= num; i++) cout << s[i];
      cout << endl;
      continue;
    }
    for (int i = k - 2; i >= 0; i--)
      if (s[i] != s[i + 1]) flag = 1;
    if (flag == 1)
      cout << s[k - 1] << endl;
    else {
      int r = s.length() - 1;
      if (s[k] != s[r])
        for (int i = k - 1; i <= r; i++) cout << s[i];
      else {
        int num = r - k + 1;
        int num1 = k;
        int num2 = num / num1;
        int num3 = num % num1;
        if (num3) num2++;
        cout << s[k - 1];
        for (int i = 1; i <= num2; i++) cout << s[k];
      }
      cout << endl;
    }
  }
  return 0;
}
