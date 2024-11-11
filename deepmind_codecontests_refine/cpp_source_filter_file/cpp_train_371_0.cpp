#include <bits/stdc++.h>
using namespace std;
int vec[26][2001];
int ans[26][1002];
int n;
string s;
int k;
int cnt, cnt_need;
int q;
char symbol;
int m;
int Ans[26][1002];
void up(int &a, int b) {
  if (b > a) a = b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) vec[j][i] = vec[j][i - 1];
    ++vec[s[i - 1] - 'a'][i];
  }
  for (int k = 0; k < 26; ++k) {
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; ++j) {
        cnt = vec[k][j] - vec[k][i - 1];
        cnt_need = (j - i + 1) - cnt;
        up(ans[k][cnt_need], j - i + 1);
      }
    for (int i = 0; i < n; ++i) up(ans[k][i + 1], ans[k][i]);
  }
  cin >> q;
  while (q-- > 0) {
    cin >> m >> symbol;
    cout << ans[symbol - 'a'][m] << '\n';
  }
}
