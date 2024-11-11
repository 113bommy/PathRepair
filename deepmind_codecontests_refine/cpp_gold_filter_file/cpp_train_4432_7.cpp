#include <bits/stdc++.h>
using namespace std;
vector<long int> vec;
set<long int> ss;
int n, m;
int main() {
  int t = 1;
  while (t--) {
    string str;
    cin >> str;
    char ch = str[str.length() - 1];
    int len = str.length();
    unsigned long long int num = 0;
    for (int i = 0; i < (len - 1); i++) num = num * 10 + (str[i] - '0');
    unsigned long long int ans = 0;
    unsigned long long int temp = num / 4;
    if (num % 4 == 0) temp--;
    ans = temp * 16;
    if (num % 4 == 1 || num % 4 == 3) {
      if (ch == 'a')
        ans += 4;
      else if (ch == 'b')
        ans += 5;
      else if (ch == 'c')
        ans += 6;
      else if (ch == 'd')
        ans += 3;
      else if (ch == 'e')
        ans += 2;
      else if (ch == 'f')
        ans++;
    } else {
      ans += 7;
      if (ch == 'a')
        ans += 4;
      else if (ch == 'b')
        ans += 5;
      else if (ch == 'c')
        ans += 6;
      else if (ch == 'd')
        ans += 3;
      else if (ch == 'e')
        ans += 2;
      else if (ch == 'f')
        ans++;
    }
    cout << ans;
  }
}
