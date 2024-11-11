#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    cin >> s;
    int now1 = 0, len = s.size() - 1;
    while (s[now1] == '0' && now1 <= len) {
      now1++;
    }
    int ans1 = 2 * (len - now1 + 1);
    int now2 = len;
    while (s[now2] == '0' && now2 >= 0) {
      now2--;
    }
    int ans2 = 2 * now2;
    printf("%d\n", max(ans1, max(ans2, n)));
  }
  return 0;
}
