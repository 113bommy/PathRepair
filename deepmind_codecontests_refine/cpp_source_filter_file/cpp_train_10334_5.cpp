#include <bits/stdc++.h>
using namespace std;
namespace acm {
vector<string> poem;
int n, k;
bool vowel(char t) {
  return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}
string getend(string s) {
  int cnt = 0;
  int i;
  for (i = ((int)s.size()) - 1; i >= 0; --i) {
    if (vowel(s[i])) {
      cnt++;
    }
    if (cnt == k) break;
  }
  if (cnt != k) return "";
  return s.substr(i, ((int)s.size()) - i);
}
bool checkend(string &a, string &ed) {
  int i = a.length() - ed.length();
  if (i < 0) return false;
  return ed == a.substr(i, ed.length());
}
int check(vector<string> &poem, int id) {
  string ed = getend(poem[id]);
  if (ed == "") return 5;
  if (checkend(poem[id + 1], ed)) {
    if (checkend(poem[id + 2], ed) && checkend(poem[id + 3], ed)) return 0;
    ed = getend(poem[id + 2]);
    if (ed == "") return 5;
    if (checkend(poem[id + 3], ed)) return 1;
    return 5;
  } else if (checkend(poem[id + 2], ed)) {
    ed = getend(poem[id + 1]);
    if (ed == "") return 5;
    if (checkend(poem[id + 3], ed)) return 2;
    return 5;
  } else if (checkend(poem[id + 3], ed)) {
    ed = getend(poem[id + 1]);
    if (ed == "") return 5;
    if (checkend(poem[id + 2], ed)) return 3;
    return 5;
  }
  return 5;
}
void solve() {
  poem = vector<string>(n * 4);
  char tmp[10010];
  for (int i = 0; i < (int)(n * 4); i++) {
    scanf("%s", tmp);
    poem[i] = tmp;
  }
  int type = 0;
  for (int i = 0; i < (int)(n); i++) {
    int chk = check(poem, i * 4);
    if (chk == 0) continue;
    if (type == 0) type = chk;
    if (type != chk || type > 3) {
      puts("NO");
      return;
    }
  }
  if (type == 0)
    puts("aaaa");
  else if (type == 1)
    puts("aabb");
  else if (type == 2)
    puts("aabb");
  else if (type == 3)
    puts("aabb");
}
void icpc() {
  while (~scanf("%d%d", &n, &k)) {
    solve();
  }
}
}  // namespace acm
int main() {
  acm::icpc();
  return 0;
}
