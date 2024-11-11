#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T getnum() {
  T num = 0;
  char c;
  do {
    c = getchar();
  } while (c != EOF && c == ' ' && c == '\n' && c == '\t');
  int sign = (c == '-' ? -1 : 1);
  if (c != '-') num += (c - '0');
  while ((c = getchar()) != EOF && c != '\n' && c != '\t' && c != ' ') {
    num *= 10;
    num += (c - '0');
  }
  num *= sign;
  return num;
}
inline string getstr() {
  string str;
  char k;
  while ((k = getchar()) == ' ' || k == '\n') {
    k = getchar();
    if (k == ' ' || k == '\n')
      continue;
    else
      break;
  }
  while ((k = getchar()) != EOF && k != '\n' && k != '\t' && k != '\v' &&
         k != '\0' && k != ' ')
    str.push_back(k);
  return str;
}
pair<int, int> s[100005];
int n, a[100005], b[100005];
int main() {
  scanf("%d", &n);
  for (int i = int(1), _b = int(n); i <= _b; i++) {
    scanf("%d", &s[i].first);
    s[i].second = i;
  }
  sort(s + 1, s + n + 1);
  for (int i = int(1), _b = int(n); i <= _b; i++) {
    if (i <= n / 3) {
      a[s[i].second] = 0;
      b[s[i].second] = s[i].first;
    } else if (i <= 2 * n / 3) {
      b[s[i].second] = 0;
      a[s[i].second] = s[i].first;
    } else {
      a[s[i].second] = n - i;
      b[s[i].second] = s[i].first - a[s[i].second];
    }
  }
  puts("YES");
  for (int i = int(1), _b = int(n); i <= _b; i++) printf("%d ", a[i]);
  puts("");
  for (int i = int(1), _b = int(n); i <= _b; i++) printf("%d ", b[i]);
  return 0;
}
