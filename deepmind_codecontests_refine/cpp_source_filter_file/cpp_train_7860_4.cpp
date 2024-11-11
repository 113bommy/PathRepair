#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return (a % b == 0 ? b : gcd(b, a % b));
}
template <typename P>
struct Cmp {
  bool operator()(const P &p1, const P &p2) {
    if (p1.first > p2.first) return true;
    if (p1.first == p2.first) return p1.second < p2.second;
    return false;
  }
};
int a[510][510], ans[510];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = int(0); i < int(m); i++) {
    int u, v;
    cin >> u >> v;
    a[u][v] = 1;
    a[v][u] = 1;
  }
  for (int i = int(1); i < int(n + 1); i++) {
    int ct = 0;
    for (int j = int(1); j < int(n + 1); j++) {
      if (a[i][j]) ct++;
    }
    if (ct == n - 1) {
      ans[i] = 2;
    }
  }
  vector<int> v1;
  for (int i = int(1); i < int(n + 1); i++) {
    if (!ans[i]) {
      ans[i] = 1;
      v1.push_back(i);
      for (int j = int(1); j < int(n + 1); j++) {
        if (a[i][j] == 1 && ans[i] == 0) {
          v1.push_back(j);
          ans[i] = 1;
        }
      }
      break;
    }
  }
  for (int i = int(0); i < int(v1.size()); i++) {
    for (int j = int(0); j < int(v1.size()); j++) {
      if (v1[i] == v1[j]) continue;
      if (!a[v1[i]][v1[j]]) {
        puts("No");
        return 0;
      }
    }
  }
  vector<int> v2;
  for (int i = int(1); i < int(n + 1); i++) {
    if (!ans[i]) {
      ans[i] = 3;
      v2.push_back(i);
    }
  }
  for (int i = int(0); i < int(v2.size()); i++) {
    for (int j = int(0); j < int(v2.size()); j++) {
      if (v2[i] == v2[j]) continue;
      if (!a[v2[i]][v2[j]]) {
        puts("No");
        return 0;
      }
    }
  }
  for (int i = int(0); i < int(v1.size()); i++) {
    for (int j = int(0); j < int(v2.size()); j++) {
      if (a[v1[i]][v2[j]]) {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  for (int i = int(1); i < int(n + 1); i++) {
    cout << (char)(ans[i] + 96);
  }
  return 0;
}
