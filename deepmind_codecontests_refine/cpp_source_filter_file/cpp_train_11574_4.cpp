#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(int x) {
  static const int maxlen = 100;
  static char s[maxlen];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (int i = len - 1; i >= 0; --i) putchar(s[i]);
}
const int MAXN = 110000;
pair<pair<int, int>, int> a[MAXN];
char s[MAXN];
int n;
string ss[MAXN];
bool isvowels(char ch) {
  if (ch == 'a') return 1;
  if (ch == 'e') return 1;
  if (ch == 'i') return 1;
  if (ch == 'o') return 1;
  if (ch == 'u') return 1;
  return 0;
}
pair<pair<int, int>, int> check(int id) {
  int len = strlen(s);
  int cnt = 0, last = 0;
  for (int i = 0; i < len; i++)
    if (isvowels(s[i])) {
      cnt++;
      last = s[i] - 'a' + 1;
    }
  return make_pair(make_pair(cnt, last), id);
}
vector<pair<int, int> > same_1, like_1;
void out(int id) {
  int len = ss[id].size();
  for (int i = 0; i < len; i++) printf("%c", ss[id][i]);
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    a[i] = check(i);
    ss[i] = string(s);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i < n; i++)
    if (a[i].first == a[i + 1].first) {
      same_1.push_back(make_pair(a[i].second, a[i + 1].second));
      a[i].first = make_pair(1e9, 1e9);
      a[i + 1].first = make_pair(1e9, 1e9);
      i = i + 1;
    }
  sort(a + 1, a + n + 1);
  for (int i = 1; i < n; i++) {
    if (a[i].first.first > 1e8) break;
    if (a[i].first.first == a[i + 1].first.first) {
      like_1.push_back(make_pair(a[i].second, a[i + 1].second));
      i = i + 1;
    }
  }
  int tmp = min(same_1.size(), like_1.size());
  printf("%d\n", tmp + (same_1.size() - tmp) / 2);
  for (int i = 0; i < tmp; i++) {
    out(like_1[i].first);
    printf(" ");
    out(same_1[i].first);
    puts("");
    out(like_1[i].second);
    printf(" ");
    out(same_1[i].second);
    puts("");
  }
  for (int i = tmp; i < same_1.size(); i += 2) {
    out(same_1[i].first);
    printf(" ");
    out(same_1[i + 1].first);
    puts("");
    out(same_1[i].second);
    printf(" ");
    out(same_1[i + 1].second);
    puts("");
  }
  return 0;
}
