#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
string str;
long long m, strl;
long long sum, ans = 1e9 + 1;
long long mods[10] = {0};
void init() {
  sum = str[0] - '0';
  for (int i = 1; i < strl; i++) sum = (sum * 10 + str[i] - '0') % m;
  for (int i = 1; i < 10; i++) mods[i] = i;
  for (int i = 0; i < strl; i++)
    for (int j = 1; j < 10; j++) mods[j] = (mods[j] * 10) % m;
}
int main(int argc, char* argv[]) {
  cin >> str >> m;
  strl = str.length();
  init();
  ans = sum;
  bool pre;
  for (long long i = 0; i < strl - 1; i++) {
    if (str[i + 1] == '0') {
      pre = 1;
    } else
      pre = 0;
    sum = ((sum + m - mods[str[i] - '0']) * 10 + str[i] - '0') % m;
    if (!pre) ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
