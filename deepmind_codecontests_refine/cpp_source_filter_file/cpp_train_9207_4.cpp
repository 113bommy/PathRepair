#include <bits/stdc++.h>
using namespace std;
string s1[105], s2[105], ans[105];
map<char, int> v1, v2;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    v1.clear();
    v2.clear();
    for (int i = 0; i < n; i++) cin >> s1[i];
    for (int i = 0; i < n; i++) cin >> s2[i];
    sort(s1, s1 + n);
    for (int i = 0; i < n; i++) v1[s1[i][0]]++;
    sort(s2, s2 + n);
    for (int i = 0; i < n; i++) v2[s2[i][0]]++;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int pos = 0;
      while (pos < n) {
        if (s2[pos] == "") {
          pos++;
          continue;
        }
        if (s1[i][0] == s2[pos][0]) {
          ans[cnt++] = s1[i] + " " + s2[pos];
          s1[i] = "";
          s2[pos] = "";
          break;
        } else if (v1[s2[pos][0]] < v2[s2[pos][0]] &&
                   (v1[s1[i][0]] >= v2[s1[i][0]])) {
          ans[cnt++] = s1[i] + " " + s2[pos];
          v1[s1[i][0]]--;
          v2[s2[pos][0]]--;
          s1[i] = "";
          s2[pos] = "";
          break;
        }
        pos++;
      }
    }
    sort(ans, ans + cnt);
    for (int i = 0; i < cnt - 1; i++) cout << ans[i] << ", ";
    cout << ans[cnt - 1] << endl;
  }
  return 0;
}
