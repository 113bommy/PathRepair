#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 6;
char s[MX];
long long ans;
int main() {
  scanf("%s", &s);
  string arr[] = {"00", "04", "08", "12", "16", "20", "24", "28", "32",
                  "36", "40", "44", "48", "52", "56", "60", "64", "68",
                  "72", "76", "80", "84", "88", "92", "96"};
  long long ans = 0;
  int len = strlen(s);
  for (int i = 0; i < len; i++)
    if (s[i] == '0' || s[i] == '4' || s[i] == '8') ans++;
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < 25; j++) {
      if (s[i] == arr[j][0] && s[i + 1] == arr[j][1]) ans += (i + 1);
    }
  }
  cout << ans;
  return 0;
}
