#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s[N][7];
bool type[N];
int n, x, y;
int name[N];
queue<int> xiny, yinx, outx, outy, usex, usey;
bool vis[N << 4];
void trans(int x, char *s) {
  stack<int> S;
  while (x) {
    S.push(x % 10);
    x /= 10;
  }
  int l = 0;
  while (!S.empty()) s[l++] = S.top() + '0', S.pop();
  s[l] = '\0';
}
string change(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
struct node {
  string a, b;
  node() {}
  node(string _a, string _b) {
    a = _a;
    b = _b;
  }
  void print() { cout << "move " << a << ' ' << b << endl; }
};
vector<node> query;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s%d", s[i], &type[i]);
    if (type[i])
      x++;
    else
      y++;
  }
  for (int i = 1; i <= n; ++i) {
    int l = strlen(s[i]);
    bool flag = 0;
    if (s[i][0] == '0') {
      if (type[i] == 1) {
        outx.push(i);
      } else {
        outy.push(i);
      }
      continue;
    }
    for (int j = 0; j < l; ++j)
      if (s[i][j] < '0' || s[i][j] > '9') {
        flag = 1;
        break;
      } else
        name[i] = name[i] * 10 + s[i][j] - '0';
    if (flag) {
      if (type[i] == 1) {
        outx.push(i);
      } else {
        outy.push(i);
      }
      continue;
    }
    vis[name[i]] = 1;
    if (name[i] <= x) {
      if (type[i] == 1)
        ;
      else
        yinx.push(i);
    } else if (name[i] <= n) {
      if (type[i] == 1) xiny.push(i);
    } else if (type[i] == 1) {
      outx.push(i);
    } else {
      outy.push(i);
    }
  }
  int empty = n + 1;
  while (vis[empty]) empty++;
  for (int i = 1; i <= x; ++i)
    if (!vis[i]) usex.push(i);
  for (int i = x + 1; i <= n; ++i)
    if (!vis[i]) usey.push(i);
  while (1) {
    bool flag = 0;
    while (!xiny.empty()) {
      int u = xiny.front();
      if (usex.empty()) break;
      int v = usex.front();
      xiny.pop();
      usex.pop();
      query.push_back(node(change(name[u]), change(v)));
      usey.push(name[u]);
      flag = 1;
    }
    while (!yinx.empty()) {
      int u = yinx.front();
      if (usey.empty()) break;
      int v = usey.front();
      yinx.pop();
      usey.pop();
      query.push_back(node(change(name[u]), change(v)));
      usex.push(name[u]);
      flag = 1;
    }
    if (!flag) break;
  }
  if (xiny.empty()) {
    while (!outx.empty()) {
      int u = outx.front();
      outx.pop();
      query.push_back(node(string(s[u]), change(usex.front())));
      usex.pop();
    }
    while (!outy.empty()) {
      int u = outy.front();
      outy.pop();
      query.push_back(node(string(s[u]), change(usey.front())));
      usey.pop();
    }
  } else {
    int u = xiny.front();
    query.push_back(node(change(name[u]), change(empty)));
    usey.push(name[u]);
    xiny.pop();
    outx.push(u);
    trans(empty, s[u]);
    while (1) {
      bool flag = 0;
      while (!xiny.empty()) {
        int u = xiny.front();
        if (usex.empty()) break;
        int v = usex.front();
        xiny.pop();
        usex.pop();
        query.push_back(node(change(name[u]), change(v)));
        usey.push(name[u]);
        flag = 1;
      }
      while (!yinx.empty()) {
        int u = yinx.front();
        if (usey.empty()) break;
        int v = usey.front();
        yinx.pop();
        usey.pop();
        query.push_back(node(change(name[u]), change(v)));
        usex.push(name[u]);
        flag = 1;
      }
      if (!flag) break;
    }
    while (!outx.empty()) {
      int u = outx.front();
      outx.pop();
      query.push_back(node(string(s[u]), change(usex.front())));
      usex.pop();
    }
    while (!outy.empty()) {
      int u = outy.front();
      outy.pop();
      query.push_back(node(string(s[u]), change(usey.front())));
      usey.pop();
    }
  }
  printf("%d\n", query.size());
  for (int i = 0; i < query.size(); ++i) query[i].print();
  return 0;
}
