#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 101, mod = 1e9 + 7, inf = 1e9 + 1;
int n, flag, t[maxn], a[maxn], q1[maxn], q2[maxn], q3[maxn], ch[maxn], b[maxn],
    tree_build[4 * maxn], tree_max[4 * maxn], m;
vector<int> no_max;
map<int, bool> numbers;
void upd_max(int id, int x, int node = 1, int L = 1, int R = n + 1) {
  if (L == R - 1) {
    tree_max[node] = x;
    return;
  }
  int mid = (L + R) / 2;
  if (id < mid) {
    upd_max(id, x, node * 2, L, mid);
  } else {
    upd_max(id, x, node * 2 + 1, mid, R);
  }
  tree_max[node] = max(tree_max[node * 2], tree_max[node * 2 + 1]);
  return;
}
int query_max(int s, int f, int node = 1, int L = 1, int R = n + 1) {
  if (s <= L && R <= f) {
    return tree_max[node];
  }
  if (f <= L || R <= s) {
    return -1;
  }
  int mid = (L + R) / 2;
  return max(query_max(s, f, node * 2, L, mid),
             query_max(s, f, node * 2 + 1, mid, R));
}
void upd_build(int s, int f, int x, int node = 1, int L = 1, int R = n + 1) {
  if (s <= L && R <= f) {
    tree_build[node] = min(x, tree_build[node]);
    return;
  }
  if (f <= L || R <= s) {
    return;
  }
  int mid = (L + R) / 2;
  upd_build(s, f, x, node * 2, L, mid);
  upd_build(s, f, x, node * 2 + 1, mid, R);
  return;
}
int query_build(int id, int node = 1, int L = 1, int R = n + 1) {
  if (L == R - 1) {
    return tree_build[node];
  }
  int mid = (L + R) / 2, e;
  if (id < mid) {
    e = query_build(id, node * 2, L, mid);
  } else {
    e = query_build(id, node * 2 + 1, mid, R);
  }
  return min(tree_build[node], e);
}
int maxi(int x) {
  for (int i = 29; i >= 0; i--) {
    if ((1 << i) - 1 <= x) {
      return (1 << i) - 1;
    }
  }
  return 0;
}
void maximize_or() {
  for (int i = 1; i <= n; i++) {
    if (a[i] == inf) {
      no_max.push_back(i);
    } else {
      if (numbers[a[i]] == 1) {
        a[i] = maxi(a[i]);
      } else {
        numbers[a[i]] = 1;
      }
    }
  }
  if (no_max.size() == 1) {
    int ors = 0, k = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != inf) {
        ors |= a[i];
      }
    }
    for (int i = 29; i >= 0; i--) {
      if ((1 << i) & ors) {
        continue;
      }
      if (0ll + k + (1 << i) <= inf - 1) {
        k += (1 << i);
      }
    }
    a[no_max[0]] = k;
  }
  if (no_max.size() == 2) {
    for (int i = 0; i < (int)no_max.size(); i++) {
      if (i == 0) {
        a[no_max[i]] = (1 << 29) - 1;
        continue;
      }
      a[no_max[i]] = 1e9;
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 4 * maxn; i++) {
    tree_build[i] = inf;
  }
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int tmp1;
    cin >> tmp1;
    if (tmp1 == 1) {
      int tmp2, tmp3, tmp4;
      cin >> tmp2 >> tmp3 >> tmp4;
      tmp3++;
      upd_build(tmp2, tmp3, tmp4);
      t[i] = tmp1;
      q1[i] = tmp2;
      q2[i] = tmp3;
      q3[i] = tmp4;
    } else {
      int tmp2, tmp3;
      cin >> tmp2 >> tmp3;
      if (ch[tmp2] == 0) {
        ch[tmp2] = 1;
        a[tmp2] = query_build(tmp2);
      }
      t[i] = tmp1;
      q1[i] = tmp2;
      q2[i] = tmp3;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ch[i] == 0) {
      a[i] = query_build(i);
    }
    b[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    upd_max(i, a[i]);
  }
  for (int i = 1; i <= m; i++) {
    if (t[i] == 2) {
      upd_max(q1[i], q2[i]);
    } else {
      int wow = query_max(q1[i], q2[i]);
      if (wow != q3[i]) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1) {
    cout << "NO" << endl;
    return 0;
  }
  maximize_or();
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
