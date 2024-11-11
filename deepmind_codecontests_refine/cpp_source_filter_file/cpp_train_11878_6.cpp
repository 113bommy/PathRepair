#include <bits/stdc++.h>
using namespace std;
const long double EPS = (long double)1e-9;
const long double PI = acos(0) * 2;
bool isZero(const long double& x) { return abs(x) <= EPS; }
int sign(const long double& x) { return isZero(x) ? 0 : (0 < x ? 1 : -1); }
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b)) {
  }
  return abs(a);
}
pair<long long, long long> operator+(const pair<long long, long long>& a,
                                     const pair<long long, long long>& b) {
  return pair<long long, long long>(a.first + b.first, a.second + b.second);
}
pair<long long, long long> operator-(const pair<long long, long long>& a,
                                     const pair<long long, long long>& b) {
  return pair<long long, long long>(a.first - b.first, a.second - b.second);
}
pair<long long, long long> operator*(const pair<long long, long long>& a,
                                     const long long& b) {
  return pair<long long, long long>(a.first * b, a.second * b);
}
long long operator*(const pair<long long, long long>& a,
                    const pair<long long, long long>& b) {
  return a.first * b.second - b.first * a.second;
}
long long ccw(const pair<long long, long long>& a,
              const pair<long long, long long>& b,
              const pair<long long, long long>& c) {
  return a * b + b * c + c * a;
}
void fg(vector<int> G[], int a, int b) {
  G[a].push_back(b);
  G[b].push_back(a);
}
void fg(vector<pair<int, int> > G[], int a, int b, int c) {
  G[a].push_back({b, c});
  G[b].push_back({a, c});
}
const int MAXN = 1000055;
int E[MAXN][2];
int D[MAXN];
char A[MAXN][6];
int B[MAXN], C[MAXN];
int N;
void dfs1(int i) {
  if ('I' == A[i][0]) {
    D[i] = B[i];
    return;
  }
  if ('N' == A[i][0]) {
    dfs1(B[i]);
    D[i] = !D[B[i]];
    return;
  }
  dfs1(B[i]);
  dfs1(C[i]);
  if ('A' == A[i][0]) {
    D[i] = D[B[i]] & D[C[i]];
  } else if ('O' == A[i][0]) {
    D[i] = D[B[i]] | D[C[i]];
  } else {
    D[i] = D[B[i]] ^ D[C[i]];
  }
}
void dfs2(int i) {
  if ('I' == A[i][0]) return;
  if ('N' == A[i][0]) {
    E[B[i]][0] = !E[i][0];
    E[B[i]][1] = !E[i][1];
    dfs2(B[i]);
    return;
  }
  if ('A' == A[i][0]) {
    E[B[i]][0] = E[i][0];
    E[B[i]][1] = E[i][D[C[i]]];
    E[C[i]][0] = E[i][0];
    E[C[i]][1] = E[i][D[B[i]]];
  } else if ('O' == A[i][0]) {
    E[B[i]][0] = E[i][D[C[i]]];
    E[B[i]][1] = E[i][1];
    E[C[i]][0] = E[i][D[B[i]]];
    E[C[i]][1] = E[i][1];
  } else {
    E[B[i]][0] = E[i][D[C[i]]];
    E[B[i]][1] = E[i][D[C[i]] ^ 1];
    E[C[i]][0] = E[i][D[B[i]]];
    E[C[i]][1] = E[i][D[B[i]] ^ 1];
  }
  dfs2(B[i]);
  dfs2(C[i]);
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf(" %s%d", A[i], &B[i]);
    if ('I' != A[i][0] && 'N' != A[i][0]) scanf("%d", &C[i]);
  }
  dfs1(1);
  E[1][0] = 0;
  E[1][1] = 1;
  dfs2(1);
  for (int i = 1; i <= N; i++)
    if ('I' == A[i][0]) putchar(E[i][!B[i]] ? '1' : '0');
  puts("");
  return 0;
}
