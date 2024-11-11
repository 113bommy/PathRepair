#include <bits/stdc++.h>
using namespace std;
string S;
bool hasDec = false;
long long process(int s, int e) {
  long long ret = 0;
  bool x = (s < e - 2 && S[e - 2] == '.');
  for (int i = s; i <= e; i++)
    if ('0' <= S[i] && S[i] <= '9') ret = 10 * ret + S[i] - '0';
  hasDec |= x;
  if (!x) return ret * 100;
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> S;
  long long total = 0;
  for (int i = 0; i < S.size();) {
    if ('a' <= S[i] && S[i] <= 'z') {
      i++;
      continue;
    }
    int j;
    for (j = i; j < S.size(); j++)
      if ('a' <= S[j] && S[j] <= 'z') break;
    total += process(i, j - 1);
    i = j;
  }
  string ans = "";
  if (hasDec && total % 100 != 0) {
    ans += (char)(total % 10 + '0');
    total /= 10;
    ans += (char)(total % 10 + '0');
    total /= 10;
    ans += '.';
  } else
    total /= 100;
  for (int i = 0; total > 0; total /= 10, i++) {
    ans += (char)(total % 10 + '0');
    if (i % 3 == 2 && total > 10) ans += '.';
  }
  if (ans[(int)ans.size() - 1] == '.') ans += '0';
  for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i];
  cout << "\n";
  return 0;
}
