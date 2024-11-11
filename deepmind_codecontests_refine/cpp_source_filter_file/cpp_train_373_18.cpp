#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int pre[MAXN], ch[MAXN][2], key[MAXN], ss[MAXN], sz[MAXN];
long long dp[MAXN][5];
int tot1, tot2;
int root;
vector<int> buf;
void push_down(int r) {
  if (!r) return;
}
void push_up(int x) {
  int l = ch[x][0], r = ch[x][1];
  sz[x] = sz[l] + sz[r] + 1;
  int lsz = sz[l] + 1;
  for (int i = 0; i < 5; i++) {
    dp[x][i] = dp[l][i];
  }
  dp[x][(sz[l]) % 5] = key[x];
  if (r) {
    for (int i = 0; i < 5; i++) {
      dp[x][(i + lsz) % 5] += dp[r][i];
    }
  }
}
void rotate(int x, int d) {
  const int y = pre[x];
  ch[y][!d] = ch[x][d];
  if (ch[x][d]) pre[ch[x][d]] = y;
  pre[x] = pre[y];
  if (ch[pre[y]][0] == y)
    ch[pre[x]][0] = x;
  else if (ch[pre[y]][1] == y)
    ch[pre[x]][1] = x;
  pre[y] = x;
  ch[x][d] = y;
  push_up(y);
}
bool _splay_parent(int x, int &y, int goal) {
  return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}
void splay(int x, int goal) {
  if (goal == 0) root = x;
  if (!x) return;
  for (int y, z; _splay_parent(x, y, goal);) {
    if (_splay_parent(y, z, goal)) {
      int d = y == ch[z][0];
      if (x == ch[y][d])
        rotate(x, d ^ 1), rotate(x, d);
      else
        rotate(y, d), rotate(x, d);
    } else {
      rotate(x, x == ch[y][0]);
      break;
    }
  }
  push_up(x);
}
int newnode(int x, int fa) {
  int r;
  tot1++;
  r = tot1;
  ch[r][0] = ch[r][1] = 0;
  key[r] = dp[r][0] = x;
  pre[r] = fa;
  for (int i = 1; i < 5; i++) dp[r][i] = 0;
  push_up(r);
  return r;
}
void insert(int cur, int x) {
  if (key[cur] > x) {
    if (ch[cur][0]) {
      insert(ch[cur][0], x);
    } else {
      ch[cur][0] = newnode(x, cur);
    }
  } else {
    if (ch[cur][1]) {
      insert(ch[cur][1], x);
    } else {
      ch[cur][1] = newnode(x, cur);
    }
  }
  push_up(cur);
}
void debug(int r) {
  if (r) {
    cout << key[r] << " : ";
    if (ch[r][0]) {
      cout << "Left Child   " << key[ch[r][0]] << "    ";
    }
    if (ch[r][1]) {
      cout << "Right Child  " << key[ch[r][1]];
    }
    cout << endl;
    if (ch[r][0]) {
      debug(ch[r][0]);
    }
    if (ch[r][1]) {
      debug(ch[r][1]);
    }
  }
}
void disp(int r) {
  cout << r << " : " << key[r] << " ";
  if (ch[r][0]) {
    cout << "Left Child   " << key[ch[r][0]] << "    ";
  }
  if (ch[r][1]) {
    cout << "Right Child  " << key[ch[r][1]];
  }
  cout << endl;
}
void remove(int cur, int x) {
  if (key[cur] == x) {
    if (ch[cur][0]) {
      int r = ch[cur][0];
      pre[r] = pre[cur];
      if (pre[cur]) {
        int fa = pre[cur];
        ch[fa][ch[fa][1] == cur] = r;
      }
      while (ch[r][1]) r = ch[r][1];
      if (ch[cur][1]) {
        pre[ch[cur][1]] = r;
        ch[r][1] = ch[cur][1];
      }
      splay(r, 0);
    } else if (ch[cur][1]) {
      int r = ch[cur][1];
      if (pre[cur]) {
        int fa = pre[cur];
        ch[fa][ch[fa][1] == cur] = r;
      }
      pre[r] = pre[cur];
      splay(r, 0);
    } else {
      if (pre[cur]) {
        int fa = pre[cur];
        ch[fa][ch[fa][1] == cur] = 0;
      }
      splay(pre[cur], 0);
    }
    return;
  } else if (key[cur] < x) {
    remove(ch[cur][1], x);
  } else {
    remove(ch[cur][0], x);
  }
}
void dfs(int r) {
  if (r) {
    dfs(ch[r][0]);
    buf.push_back(key[r]);
    dfs(ch[r][1]);
  }
}
int rebuild(int x, int L, int R) {
  if (R < L) return 0;
  int mid = (L + R) >> 1;
  int ret = newnode(buf[mid], x);
  ch[ret][0] = rebuild(ret, L, mid - 1);
  ch[ret][1] = rebuild(ret, mid + 1, R);
  push_up(ret);
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  scanf("%d", &t);
  char op[10];
  int x;
  int opt = 0;
  while (t--) {
    scanf("%s", op);
    if (op[0] == 's') {
      cout << dp[root][2] << endl;
    } else if (op[0] == 'a') {
      scanf("%d", &x);
      if (root == 0)
        root = newnode(x, root);
      else
        insert(root, x);
      opt++;
      if (opt % 5 == 0 && root) {
        buf.clear();
        dfs(root);
        root = 0;
        tot1 = 0;
        root = rebuild(0, 0, (int)buf.size() - 1);
      }
    } else {
      scanf("%d", &x);
      remove(root, x);
    }
  }
  return 0;
}
