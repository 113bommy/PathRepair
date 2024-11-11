#include <bits/stdc++.h>
using namespace std;
char names[50][31];
int n;
int id(char *s) {
  for (int i = 0; i < n; ++i)
    if (0 == strcmp(s, names[i])) return i;
  return -1;
}
struct team {
  int id;
  int score;
  int lose;
  int goal;
  bool operator<(const team &t) const {
    if (score > t.score)
      return true;
    else if (score < t.score)
      return false;
    if (goal - lose < t.goal - t.lose)
      return true;
    else if (goal - lose > t.goal - t.lose)
      return false;
    if (goal > t.goal)
      return true;
    else if (goal < t.goal)
      return false;
    return id < t.id;
  }
};
team t[50];
char s1[101], *s2;
int p, q;
char ch;
string ss[50];
int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) scanf("%s\n", names[i]);
  memset(t, 0, sizeof(t));
  for (int i = 0; i < n; ++i) t[i].id = i;
  for (int i = n * (n - 1) / 2; i > 0; --i) {
    scanf("%s %d:%d\n", s1, &p, &q);
    for (s2 = s1; '-' != *s2; ++s2)
      ;
    *(s2++) = '\0';
    int x = id(s1);
    int y = id(s2);
    t[x].lose += q;
    t[x].goal += p;
    t[y].lose += p;
    t[y].goal += q;
    if (p > q)
      t[x].score += 3;
    else if (p < q)
      t[y].score += 3;
    else {
      ++t[x].score;
      ++t[y].score;
    }
  }
  std::sort(t, t + n);
  for (int i = 0; i < n / 2; ++i) ss[i] = names[t[i].id];
  std::sort(ss, ss + n / 2);
  for (int i = 0; i < n / 2; ++i) puts(ss[i].c_str());
  return 0;
}
