#include <bits/stdc++.h>
using namespace std;
map<int, char> m1;
map<char, int> m2;
char s[105];
int n, i, j, k;
int main() {
  scanf("%s", &s);
  n = strlen(s);
  for (i = 0; i < n; i++)
    if (s[i] != '!') m1[i % 4] = s[i];
  for (i = 0; i < n; i++) {
    if (s[i] != '!') continue;
    m2[m1[(i + 1) % 4]]++;
  }
  printf("%d %d %d %d\n", m2['R'], m2['B'], m2['Y'], m2['G']);
  return 0;
}
