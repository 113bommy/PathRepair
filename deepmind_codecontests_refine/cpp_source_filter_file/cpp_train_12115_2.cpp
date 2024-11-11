#include <bits/stdc++.h>
using namespace std;
int DP[360361];
int DP1[360361], DP2[360361];
queue<int> q;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long a, b, k;
  cin >> a >> b >> k;
  long long lcm = 1;
  for (int i = 2; i <= k; i++) {
    lcm = lcm * i / gcd(lcm, i);
  }
  memset(DP, -1, sizeof(DP));
  memset(DP1, -1, sizeof(DP1));
  memset(DP2, -1, sizeof(DP2));
  q.push(lcm);
  DP[lcm] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u <= 0) continue;
    int v = u - 1;
    if (DP[v] == -1 || DP[v] > DP[u] + 1) {
      DP[v] = DP[u] + 1;
      q.push(v);
    }
    for (int i = 2; i <= k; i++) {
      v = u - (u % i);
      if (v < 0) continue;
      if (DP[v] == -1 || DP[v] > DP[u] + 1) {
        DP[v] = DP[u] + 1;
        q.push(v);
      }
    }
  }
  long long fi = (b / lcm + 1) * lcm;
  long long se = (a / lcm) * lcm;
  long long ans = 0;
  if (fi >= se) {
    queue<long long> q;
    q.push(a - b);
    DP1[a - b] = 0;
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      if (u <= 0) continue;
      long long v = u - 1;
      if (DP1[v] == -1 || DP1[v] > DP1[u] + 1) {
        DP1[v] = DP1[u] + 1;
        q.push(v);
      }
      for (int i = 2; i <= k; i++) {
        v = u - ((u + b) % i);
        if (v < 0) continue;
        if (DP1[v] == -1 || DP1[v] > DP1[u] + 1) {
          DP1[v] = DP1[u] + 1;
          q.push(v);
        }
      }
    }
    ans = DP1[0];
  } else {
    queue<long long> q;
    q.push(a - se);
    DP1[a - se] = 0;
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      if (u <= 0) continue;
      long long v = u - 1;
      if (DP1[v] == -1 || DP1[v] > DP1[u] + 1) {
        DP1[v] = DP1[u] + 1;
        q.push(v);
      }
      for (int i = 2; i <= k; i++) {
        v = u - ((u + se) % i);
        if (v < 0) continue;
        if (DP1[v] == -1 || DP1[v] > DP1[u] + 1) {
          DP1[v] = DP1[u] + 1;
          q.push(v);
        }
      }
    }
    q.push(fi - b);
    DP2[fi - b] = 0;
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      if (u <= 0) continue;
      long long v = u - 1;
      if (DP2[v] == -1 || DP2[v] > DP2[u] + 1) {
        DP2[v] = DP2[u] + 1;
        q.push(v);
      }
      for (int i = 2; i <= k; i++) {
        v = u - ((u + b) % i);
        if (v < 0) continue;
        if (DP2[v] == -1 || DP2[v] > DP2[u] + 1) {
          DP2[v] = DP2[u] + 1;
          q.push(v);
        }
      }
    }
    ans = DP1[0] + (se - fi) / lcm * DP[0] + DP2[0];
  }
  printf("%lld", ans);
}
