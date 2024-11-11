#include <bits/stdc++.h>
using namespace std;
long long int isCheck(string str, long long int n, long long int k, char t) {
  long long int i = 0, j = 0, cnt = 0, ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (str[i] == t) cnt++;
    if (cnt > k) {
      while (cnt > k) {
        if (str[j++] == t) cnt--;
      }
    }
    ans = max(ans, abs(j - i) + 1);
  }
  return ans;
}
long long int n, k;
string str;
int main() {
  cin >> n >> k;
  cin >> str;
  cout << max(isCheck(str, n, k, 'a'), isCheck(str, n, k, 'b'));
  return 0;
}
