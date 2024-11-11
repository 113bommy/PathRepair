#include <bits/stdc++.h>
using namespace std;
const int maxlen = 1000002, maxm = 4001;
char s[maxlen];
int m;
map<int, int> ans;
bool qq[1 << 27];
int queries[maxm];
int main() {
  scanf("%s", s);
  scanf("%d", &m);
  for (int i = (0); i < (m); i++) {
    char q[30];
    scanf("%s", q);
    int len = strlen(q);
    int mask = 0;
    for (int j = (0); j < (len); j++) mask |= (1 << (q[j] - 'a'));
    queries[i] = mask;
    qq[mask] = 1;
  }
  int last[26];
  for (int i = (0); i < (26); i++) last[i] = -1;
  int n = strlen(s);
  for (int i = (0); i < (n); i++) {
    if (i < n - 1 && s[i] == s[i + 1]) {
      last[s[i] - 'a'] = i;
      continue;
    }
    int from = (i == n - 1 ? -1 : last[s[i + 1] - 'a']);
    last[s[i] - 'a'] = i;
    pair<int, char> last_cop[26];
    for (int j = (0); j < (26); j++)
      last_cop[j].first = last[j], last_cop[j].second = j;
    sort(last_cop, last_cop + 26);
    int current_mask = 0;
    for (int j = 25; j >= 0 && last_cop[j].first > from; j--) {
      current_mask |= (1 << (last_cop[j].second));
      if (qq[current_mask]) ans[current_mask]++;
    }
  }
  for (int i = (0); i < (m); i++) {
    cout << ans[queries[i]] << endl;
  }
}
