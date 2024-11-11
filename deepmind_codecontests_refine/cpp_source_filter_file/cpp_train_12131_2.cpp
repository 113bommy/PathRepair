#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100005;
struct Node {
  char c;
  int pos;
  Node() {}
  Node(char _c, int _pos) : c(_c), pos(_pos) {}
  bool operator<(const Node& rhs) const {
    if (c != rhs.c) return c < rhs.c;
    return pos < rhs.pos;
  }
};
Node p[N];
vector<int> q[26];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    p[i].c = s[i];
    p[i].pos = i + 1;
  }
  int len = s.size();
  sort(p, p + len);
  for (int i = 0; i < len; ++i) {
    q[p[i].c - 'a'].push_back(p[i].pos);
  }
  for (int i = 1; i <= n; ++i) {
    string t;
    cin >> t;
    LL res = 0;
    for (int i = 0; i < t.size(); ++i) {
      if (q[t[i] - 'a'].size() == 0) {
        res += t.size();
      } else {
        int d = 0;
        int pos =
            lower_bound(q[t[i] - 'a'].begin(), q[t[i] - 'a'].end(), i + 1) -
            q[t[i] - 'a'].begin();
        if (pos == q[t[i] - 'a'].size())
          d = abs(i + 1 - q[t[i] - 'a'][pos - 1]);
        else if (pos == 0) {
          d = abs(i + 1 - q[t[i] - 'a'][pos]);
        } else {
          d = min(abs(i + 1 - q[t[i] - 'a'][pos - 1]),
                  abs(i + 1 - q[t[i] - 'a'][pos]));
        }
        res += d;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
