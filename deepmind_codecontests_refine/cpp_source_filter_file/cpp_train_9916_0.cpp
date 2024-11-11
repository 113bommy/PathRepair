#include <bits/stdc++.h>
using namespace std;
template <class T>
void _deb(const char *name, T val) {
  cout << name << val << endl;
}
const int maxn = 128;
int t;
char s[maxn];
int numOf0[maxn];
int numOf1[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(s, 0, sizeof(s));
    scanf("%s", s + 1);
    int last;
    for (int i = 1; s[i] != 0; i++) {
      int ele = s[i] - '0';
      numOf0[i] = numOf0[i - 1] + (int)(ele == 0);
      numOf1[i] = numOf1[i - 1] + (int)(ele == 1);
      last = i;
    }
    int ans = INT_MAX;
    for (int i = 1; s[i] != 0; i++) {
      ans = min(ans, numOf0[i] + (numOf1[last] - numOf1[i]));
      ans = min(ans, numOf1[i] + (numOf0[last] - numOf0[i]));
    }
    printf("%d\n", ans);
  }
  return 0;
}
