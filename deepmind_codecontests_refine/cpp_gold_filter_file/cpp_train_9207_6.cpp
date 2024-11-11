#include <bits/stdc++.h>
using namespace std;
int used[105];
int main() {
  for (int i = 0; i < ((int)105); i++) used[i] = false;
  int n;
  cin >> n;
  vector<string> a(n), b(n);
  for (int i = 0; i < ((int)n); i++) cin >> a[i];
  for (int i = 0; i < ((int)n); i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int cnt[2][26];
  for (int i = 0; i < ((int)2); i++)
    for (int j = 0; j < ((int)26); j++) cnt[i][j] = 0;
  for (int i = 0; i < ((int)n); i++) cnt[0][a[i][0] - 'A']++;
  for (int i = 0; i < ((int)n); i++) cnt[1][b[i][0] - 'A']++;
  for (int i = 0; i < ((int)n); i++) {
    if (i) cout << ", ";
    cout << a[i] << " ";
    for (int j = 0; j < ((int)n); j++)
      if (a[i][0] == b[j][0] ||
          (cnt[0][a[i][0] - 'A'] > cnt[1][a[i][0] - 'A'] &&
           cnt[1][b[j][0] - 'A'] > cnt[0][b[j][0] - 'A'])) {
        if (used[j]) continue;
        used[j] = true;
        cout << b[j];
        cnt[0][a[i][0] - 'A']--;
        cnt[1][b[j][0] - 'A']--;
        break;
      }
  }
}
