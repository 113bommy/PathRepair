#include <bits/stdc++.h>
using namespace std;
char dict[256];
char str[200000];
pair<char, char> p[100000];
int main() {
  int n, m;
  cin >> n >> m;
  scanf("%s", str);
  for (char j = 'a'; j <= 'z'; j++) {
    dict[j] = j;
  }
  getchar();
  for (int i = 0; i < m; i++) {
    scanf("%c %c", &p[i].first, &p[i].second);
    if (i != m - 1) getchar();
  }
  for (int i = 0; i < m; i++) {
    for (char c = 'a'; c <= 'z'; ++c) {
      if (dict[c] == p[i].first)
        dict[c] = p[i].second;
      else if (dict[c] == p[i].second)
        dict[c] = p[i].first;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%c", dict[str[i]]);
  }
  return 0;
}
