#include <bits/stdc++.h>
using namespace std;
int n, v[110];
string s;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) cin >> v[i];
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    getline(cin, s);
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
          s[j] == 'u' || s[j] == 'y')
        cnt++;
    }
    if (cnt != v[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
