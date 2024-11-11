#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[] = {1, -1, 0, 0, -1, 1, 1, -1};
bool f[26];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  string s;
  cin >> s;
  char mn = *min_element((s).begin(), (s).end());
  char mx = *max_element((s).begin(), (s).end());
  if (k > n) {
    cout << s;
    for (int i = 0; i < k - n; i++) cout << mn;
    return 0;
  }
  for (int i = 0; i < s.size(); i++) f[s[i] - 'a']++;
  int pos;
  for (int i = k - 1; i >= 0; i--) {
    if (s[i] != mx) {
      pos = i;
      break;
    }
  }
  for (int i = 0; i < pos; i++) cout << s[i];
  for (int i = 0; i < 26; i++) {
    if (f[i] && i > s[pos] - 'a') {
      cout << char(i + 'a');
      break;
    }
  }
  for (int i = pos + 1; i < k; i++) cout << mn;
}
