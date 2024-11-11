#include <bits/stdc++.h>
using namespace std;
vector<long long> grp[505];
long long vis[505];
long long dfs(long long cur, long long cnt) {
  vis[cur] = cnt;
  long long ans = 1;
  long long i, k = grp[cur].size();
  for (i = 0; i < k; i++) {
    long long nxt = grp[cur][i];
    if (vis[nxt] == 0) {
      ans += dfs(nxt, cnt);
    }
  }
  return ans;
}
int dfs3(long long cur, long long cnt) {
  vis[cur] = cnt;
  long long i, k = grp[cur].size();
  long long ans;
  for (i = 0; i < k; i++) {
    long long nxt = grp[cur][i];
    if (vis[nxt] == 0) {
      long long ans = dfs3(nxt, cnt);
      if (ans == -1) return -1;
    } else if (vis[nxt] == 1) {
      return -1;
    }
  }
  return 1;
}
void dfs1(long long cur, long long cnt) {
  vis[cur] = cnt;
  long long i, k = grp[cur].size();
  for (i = 0; i < k; i++) {
    long long nxt = grp[cur][i];
    if (vis[nxt] == 0) {
      dfs1(nxt, cnt);
    }
  }
}
int main() {
  long long flag, i, j, k, l, m, n, a, b;
  scanf("%lld", &n);
  scanf("%lld", &m);
  for (i = 0; i < m; i++) {
    scanf("%lld", &a);
    scanf("%lld", &b);
    a--;
    b--;
    grp[a].push_back(b);
    grp[b].push_back(a);
  }
  long long cnt = 1;
  int arr[3];
  for (i = 0; i < n; i++) {
    if (vis[i] == 0) {
      arr[cnt] = dfs(i, cnt);
      cnt++;
    }
  }
  if (cnt > 3) {
    cout << "No\n";
    return 0;
  } else if (cnt == 3) {
    flag = 0;
    for (i = 0; i < n; i++) {
      k = grp[i].size();
      if (vis[i] == 1 && k != arr[1] - 1) {
        flag = 1;
        break;
      } else if (vis[i] == 2 && k != arr[2] - 1) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      for (i = 0; i < n; i++) {
        if (vis[i] == 1)
          cout << "a";
        else
          cout << "b";
      }
      cout << endl;
    }
  } else {
    for (i = 0; i < n; i++) vis[i] = 0;
    for (i = 0; i < n; i++) {
      k = grp[i].size();
      if (k == n - 1) {
        vis[i] = 2;
      }
    }
    for (i = 0; i < n; i++) {
      if (vis[i] == 0) {
        dfs1(i, 1);
        break;
      }
    }
    long long an;
    for (i = 0; i < n; i++) {
      if (vis[i] == 0) {
        an = dfs3(i, 3);
        break;
      }
    }
    if (an == -1) {
      cout << "No\n";
    } else {
      long long na = 0, nb = 0, nc = 0;
      for (i = 0; i < n; i++) {
        if (vis[i] == 1)
          na++;
        else if (vis[i] == 2)
          nb++;
        else if (vis[i] == 3)
          nc++;
      }
      if (na + nb + nc < n) {
        cout << "No\n";
        return 0;
      }
      for (i = 0; i < n; i++) {
        k = grp[i].size();
        if (vis[i] == 1 && k != nb + na - 1) {
          cout << "No\n";
          return 0;
        } else if (vis[i] == 3 && k != nb + nc - 1) {
          cout << "No\n";
          return 0;
        }
      }
      cout << "Yes\n";
      for (i = 0; i < n; i++) {
        if (vis[i] == 1)
          cout << "a";
        else if (vis[i] == 2)
          cout << "b";
        else
          cout << "c";
      }
      cout << endl;
      return 0;
    }
  }
  return 0;
}
