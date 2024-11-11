#include <bits/stdc++.h>
using namespace std;
long long p[8][3];
long long ans[8][3];
int vis[8];
long long mul(long long a[], long long b[], long long c[]) {
  long long ans = 0;
  for (int i = 0; i < 3; i++) {
    ans += (a[i] - b[i]) * (b[i] - c[i]);
  }
  return ans;
}
long long dis2(long long a[], long long b[]) {
  long long ans = 0;
  for (int i = 0; i < 3; i++) {
    ans += (a[i] - b[i]) * (a[i] - b[i]);
  }
  return ans;
}
bool dfs(int depth) {
  if (depth >= 2 && dis2(ans[depth - 1], ans[depth - 2]) == 0) {
    return false;
  }
  if (depth == 4 && mul(ans[2], ans[3], ans[0])) {
    return false;
  }
  if (depth == 8) {
    if (mul(ans[7], ans[4], ans[5])) {
      return false;
    }
    if (mul(ans[7], ans[0], ans[1]) || mul(ans[7], ans[0], ans[3])) {
      return false;
    }
    if (mul(ans[0], ans[7], ans[4]) || mul(ans[0], ans[7], ans[6])) {
      return false;
    }
    long long a = dis2(ans[0], ans[7]);
    long long b = dis2(ans[1], ans[6]);
    long long c = dis2(ans[2], ans[5]);
    long long d = dis2(ans[3], ans[4]);
    return a == b && b == c && c == d;
  }
  for (int i = 1; i < 8; i++) {
    if (vis[i] < 0) {
      vis[i] = depth;
      sort(p[i], p[i] + 3);
      do {
        if (depth < 2 || mul(ans[depth - 2], ans[depth - 1], p[i]) == 0) {
          for (int j = 0; j < 3; j++) {
            ans[depth][j] = p[i][j];
          }
          if (dfs(depth + 1)) {
            return true;
          }
        }
      } while (next_permutation(p[i], p[i] + 3));
      vis[i] = -1;
    }
  }
  return false;
}
int main() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> p[i][j];
      ans[i][j] = 0;
    }
    vis[i] = -1;
  }
  vis[0] = 0;
  for (int i = 0; i < 3; i++) {
    ans[0][i] = p[0][i];
  }
  if (dfs(1)) {
    cout << "YES" << endl;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 3; j++) {
        cout << ans[vis[i]][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
