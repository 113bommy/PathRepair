#include <bits/stdc++.h>
#pragma comment(linker, "/stack:640000000")
using namespace std;
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = acos(-1.0);
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int t, n, m;
struct node {
  int endmark;
  int mark;
  node *next[5 + 1];
  node() {
    endmark = mark = 0;
    for (int i = 0; i < 5; i++) next[i] = NULL;
  }
} * root;
int fck;
void insert(string str, int len) {
  node *curr = root;
  for (int i = 0; i < len; i++) {
    int id = str[i] - 'a';
    if (curr->next[id] == NULL) curr->next[id] = new node();
    curr = curr->next[id];
  }
  curr->endmark++;
}
string str;
int dfs(node *curr, int pos) {
  if (pos == str.size()) {
    if (curr->mark == fck) return 0;
    curr->mark = fck;
    return curr->endmark;
  }
  if (str[pos] == '?') {
    int ans = 0;
    for (int i = 0; i < (5); i++)
      if (curr->next[i] != NULL) ans += dfs(curr->next[i], pos + 1);
    ans += dfs(curr, pos + 1);
    return ans;
  } else {
    int id = str[pos] - 'a';
    if (curr->next[id] == NULL) return 0;
    return dfs(curr->next[id], pos + 1);
  }
}
void del(node *cur) {
  for (int i = 0; i < 5; i++)
    if (cur->next[i]) del(cur->next[i]);
  delete (cur);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  string s;
  root = new node();
  for (int i = 1; i <= (n); i++) {
    cin >> s;
    insert(s, s.size());
  }
  for (int i = 1; i <= (m); i++) {
    fck++;
    cin >> str;
    printf("%d\n", dfs(root, 0));
  }
  del(root);
  return 0;
}
