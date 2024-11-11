#include <bits/stdc++.h>
using namespace std;
int main() {
  int _t;
  scanf("%d", &_t);
  while (_t--) {
    string S;
    cin >> S;
    int n = S.size();
    int ans = 0;
    int seg_begin = 0, prev_end = -1;
    bool check = false;
    for (int i = 0; i < n; i++) {
      if (S[i] == '1' && !check) {
        check = 1;
        seg_begin = i;
        if (prev_end != -1) ans += (seg_begin - prev_end - 1);
      } else if (S[i] == '0' && check) {
        check = 0;
        prev_end = i - 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
