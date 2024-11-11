#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
char s[2005], s1[2005];
int n;
void shif(int x) {
  char tmp[2005];
  int cnt = 1;
  for (int i = n; i > n - x; i--) tmp[cnt++] = s[i];
  for (int j = 1; j <= n - x; j++) tmp[cnt++] = s[j];
  for (int i = 1; i <= n; i++) s[i] = tmp[i];
}
int main() {
  cin >> n;
  int cnt[27] = {0};
  cin >> s + 1 >> s1 + 1;
  for (int i = 1; i <= n; i++) {
    cnt[s1[i] - 'a']++;
    cnt[s[i] - 'a']--;
  }
  for (int i = 0; i < 27; i++)
    if (cnt[i]) {
      cout << -1 << endl;
      return 0;
    }
  cout << n * 3 << endl;
  for (int i = 1; i <= n; i++) {
    int pos;
    for (int j = 1; j <= n; j++) {
      if (s[j] == s1[i]) {
        pos = j;
        break;
      }
    }
    cout << n - pos << " " << 1 << " " << n << " ";
    shif(n - pos);
    shif(1);
    shif(n);
  }
}
