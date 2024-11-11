#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long int MAX = 1e9 + 7;
void array_show(int *array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%d%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(long long int *array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%lld%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(vector<int> &vec_s, int vec_n = -1, char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%d%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
void array_show(vector<long long int> &vec_s, int vec_n = -1,
                char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%lld%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
vector<int> path[110000];
vector<int> path2[110000];
vector<int> v1;
int v2[110000][2];
void create(int pos, int bef) {
  for (auto to : path[pos]) {
    if (to == bef) continue;
    path2[pos].push_back(to);
    create(to, pos);
  }
  v1.push_back(pos);
}
int dfs(int val) {
  int a, b, c;
  for (int pos : v1) {
    v2[pos][0] = 0, v2[pos][1] = 0;
    a = 0, b = 0;
    for (auto to : path2[pos]) {
      v2[pos][0] += v2[to][0];
      c = v2[to][1];
      if (a < c) swap(a, c);
      if (b < c) swap(b, c);
    }
    if (a + b + 1 >= val)
      v2[pos][0]++;
    else
      v2[pos][1] = a + 1;
  }
  return v2[0][0];
}
const int B = 330;
int main() {
  int n, m;
  int i, j, k;
  int a, b, c;
  cin >> n;
  vector<int> vs(n);
  for (i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--, b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  create(0, -1);
  for (i = 0; i < B && i < n; i++) {
    vs[i] = dfs(i + 1);
  }
  if (n <= B) {
    array_show(vs, vs.size(), '\n');
    return 0;
  }
  a = B;
  int z[3];
  vector<int> vz(B, n);
  for (i = B - 1; i >= 0; i--) {
    z[0] = a, z[1] = vz[i];
    while (z[1] - z[0] > 1) {
      z[2] = (z[0] + z[1]) / 2;
      b = dfs(z[2]);
      if (b <= i) {
        z[1] = z[2];
        vz[b] = min(vz[b], z[2]);
      } else
        z[0] = z[2];
    }
    for (j = a; j < z[1]; j++) {
      vs[j] = i + 1;
    }
    for (j = 1; j < i; j++) {
      vz[j] = min(vz[j], vz[j - 1]);
    }
    a = z[1];
  }
  array_show(vs, vs.size(), '\n');
}
