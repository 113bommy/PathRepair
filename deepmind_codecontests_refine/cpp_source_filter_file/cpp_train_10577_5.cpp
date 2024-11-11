#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> &a) {
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << " ";
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, vector<vector<T> > &a) {
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << endl;
  return cout;
}
string s;
int a[100000];
int f(char s) {
  if (s == 'A')
    return 0;
  else if (s == 'T')
    return 1;
  else if (s == 'G')
    return 2;
  else
    return 3;
}
struct nyx {
  int div5[5];
  int div6[6];
  int div7[7];
  int div8[8];
  int div9[9];
  int div10[10];
} tree[400000][4];
void build(int x = 0, int l = 0, int r = s.size() - 1) {
  if (l == r) {
    tree[x][a[l]].div5[0] = 1;
    tree[x][a[l]].div6[0] = 1;
    tree[x][a[l]].div7[0] = 1;
    tree[x][a[l]].div8[0] = 1;
    tree[x][a[l]].div9[0] = 1;
    tree[x][a[l]].div10[0] = 10;
    return;
  }
  int m = (l + r) / 2;
  build(2 * x + 1, l, m);
  build(2 * x + 2, m + 1, r);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      tree[x][i].div5[j] =
          tree[2 * x + 1][i].div5[j] +
          tree[2 * x + 2][i].div5[((j + l - m - 1) % 5 + 5) % 5];
    }
    for (int j = 0; j < 6; ++j) {
      tree[x][i].div6[j] =
          tree[2 * x + 1][i].div6[j] +
          tree[2 * x + 2][i].div6[((j + l - m - 1) % 6 + 6) % 6];
    }
    for (int j = 0; j < 7; ++j) {
      tree[x][i].div7[j] =
          tree[2 * x + 1][i].div7[j] +
          tree[2 * x + 2][i].div7[((j + l - m - 1) % 7 + 7) % 7];
    }
    for (int j = 0; j < 8; ++j) {
      tree[x][i].div8[j] =
          tree[2 * x + 1][i].div8[j] +
          tree[2 * x + 2][i].div8[((j + l - m - 1) % 8 + 8) % 8];
    }
    for (int j = 0; j < 9; ++j) {
      tree[x][i].div9[j] =
          tree[2 * x + 1][i].div9[j] +
          tree[2 * x + 2][i].div9[((j + l - m - 1) % 9 + 9) % 9];
    }
    for (int j = 0; j < 10; ++j) {
      tree[x][i].div10[j] =
          tree[2 * x + 1][i].div10[j] +
          tree[2 * x + 2][i].div10[((j + l - m - 1) % 10 + 10) % 10];
    }
  }
}
void update(int prev, int next, int l, int x = 0, int curL = 0,
            int curR = s.size() - 1) {
  if (l == curL && l == curR) {
    tree[x][prev].div5[0] = 0;
    tree[x][prev].div6[0] = 0;
    tree[x][prev].div7[0] = 0;
    tree[x][prev].div8[0] = 0;
    tree[x][prev].div9[0] = 0;
    tree[x][prev].div10[0] = 0;
    tree[x][next].div5[0] = 1;
    tree[x][next].div6[0] = 1;
    tree[x][next].div7[0] = 1;
    tree[x][next].div8[0] = 1;
    tree[x][next].div9[0] = 1;
    tree[x][next].div10[0] = 1;
    return;
  }
  int m = (curL + curR) / 2;
  if (l <= m)
    update(prev, next, l, 2 * x + 1, curL, m);
  else
    update(prev, next, l, 2 * x + 2, m + 1, curR);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      tree[x][i].div5[j] =
          tree[2 * x + 1][i].div5[j] +
          tree[2 * x + 2][i].div5[((j + curL - m - 1) % 5 + 5) % 5];
    }
    for (int j = 0; j < 6; ++j) {
      tree[x][i].div6[j] =
          tree[2 * x + 1][i].div6[j] +
          tree[2 * x + 2][i].div6[((j + curL - m - 1) % 6 + 6) % 6];
    }
    for (int j = 0; j < 7; ++j) {
      tree[x][i].div7[j] =
          tree[2 * x + 1][i].div7[j] +
          tree[2 * x + 2][i].div7[((j + curL - m - 1) % 7 + 7) % 7];
    }
    for (int j = 0; j < 8; ++j) {
      tree[x][i].div8[j] =
          tree[2 * x + 1][i].div8[j] +
          tree[2 * x + 2][i].div8[((j + curL - m - 1) % 8 + 8) % 8];
    }
    for (int j = 0; j < 9; ++j) {
      tree[x][i].div9[j] =
          tree[2 * x + 1][i].div9[j] +
          tree[2 * x + 2][i].div9[((j + curL - m - 1) % 9 + 9) % 9];
    }
    for (int j = 0; j < 10; ++j) {
      tree[x][i].div10[j] =
          tree[2 * x + 1][i].div10[j] +
          tree[2 * x + 2][i].div10[((j + curL - m - 1) % 10 + 10) % 10];
    }
  }
}
int find(int obj, int mod, int val, int l, int r, int x = 0, int curL = 0,
         int curR = s.size() - 1) {
  if (l > r || curL > curR) return 0;
  if (curL == l && curR == r) {
    int ans = 0;
    if (mod == 5) {
      ans += tree[x][obj].div5[val % 5];
    } else if (mod == 7) {
      ans += tree[x][obj].div7[val % 7];
    } else if (mod == 8) {
      ans += tree[x][obj].div8[val % 8];
    } else if (mod == 4) {
      ans += tree[x][obj].div8[val % 8] + tree[x][obj].div8[(val + 4) % 8];
    } else if (mod == 2) {
      ans += tree[x][obj].div8[val % 8] + tree[x][obj].div8[(val + 2) % 8] +
             tree[x][obj].div8[(val + 4) % 8] +
             tree[x][obj].div8[(val + 6) % 8];
    } else if (mod == 9) {
      ans += tree[x][obj].div9[val % 9];
    } else if (mod == 3) {
      ans += tree[x][obj].div9[val % 9] + tree[x][obj].div9[(val + 3) % 9] +
             tree[x][obj].div9[(val + 6) % 9];
    } else if (mod == 1) {
      for (int i = 0; i < 5; ++i) {
        ans += tree[x][obj].div5[i];
      }
    } else if (mod == 6) {
      ans += tree[x][obj].div6[val % 6];
    } else if (mod == 10) {
      ans += tree[x][obj].div10[val % 10];
    }
    return ans;
  }
  int m = (curL + curR) / 2;
  if (m < l)
    return find(obj, mod, val, l, r, 2 * x + 2, m + 1, curR);
  else if (m >= r)
    return find(obj, mod, val, l, r, 2 * x + 1, curL, m);
  return find(obj, mod, val, l, m, 2 * x + 1, curL, m) +
         find(obj, mod, ((val - (m - l + 1)) % mod + mod) % mod, m + 1, r,
              2 * x + 2, m + 1, curR);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    a[i] = f(s[i]);
  }
  build();
  int q;
  cin >> q;
  int t, l, r;
  string tmp;
  int ans = 0;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> l >> tmp;
      --l;
      update(f(s[l]), f(tmp[0]), l);
      s[l] = tmp[0];
    } else {
      cin >> l >> r >> tmp;
      --l;
      --r;
      ans = 0;
      for (int i = 0; i < tmp.size(); ++i) {
        ans += find(f(tmp[i]), tmp.size(), i, l, r);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
