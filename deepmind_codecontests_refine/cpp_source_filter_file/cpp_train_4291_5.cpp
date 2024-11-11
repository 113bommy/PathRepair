#include <bits/stdc++.h>
using namespace std;
const int MAX = 205;
char input[MAX], s[MAX];
vector<int> v;
map<char, char> mp;
int main() {
  mp['W'] = 'B';
  mp['B'] = 'W';
  int n;
  scanf("%d%s", &n, input);
  strcpy(s, input);
  int tot = 0;
  for (int i = 0; i < n - 1; i++)
    if (s[i] == 'W') {
      s[i] = 'B';
      s[i + 1] = mp[s[i + 1]];
      tot++;
      v.push_back(i);
    }
  if (s[n - 1] == 'B') {
    printf("%d\n", tot);
    for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
  }
  tot = 0;
  v.clear();
  strcpy(s, input);
  for (int i = 0; i < n - 1; i++)
    if (s[i] == 'B') {
      s[i] = 'W';
      s[i + 1] = mp[s[i + 1]];
      tot++;
      v.push_back(i);
    }
  if (s[n - 1] == 'W') {
    printf("%d\n", tot);
    for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
  }
  printf("-1\n");
}
