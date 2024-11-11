#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
const int N = 1 << 16;
void solve0(long long a[], long long b[], long long c[]) {
  static long long A[N], B[N], C[N];
  for (int i = 0; i <= N - 1; i++) A[i] = a[i], B[i] = b[i];
  for (int i = 0; i <= 0xf; i++) {
    int k = 1 << i;
    for (int j = 0; j <= N - 1; j++)
      if ((j ^ k) < j) {
        (A[j] += A[j ^ k]) %= P;
        (B[j] += B[j ^ k]) %= P;
      }
  }
  for (int i = 0; i <= N - 1; i++) C[i] = A[i] * B[i] % P;
  for (int i = 0; i <= 0xf; i++) {
    int k = 1 << i;
    for (int j = 0; j <= N - 1; j++)
      if ((j ^ k) < j) (C[j] -= C[j ^ k]) %= P;
  }
  for (int i = 0; i <= N - 1; i++) (c[i] += C[i]) %= P;
}
void solve1(long long a[], long long b[], long long c[]) {
  static long long A[N], B[N], C[N];
  for (int i = 0; i <= N - 1; i++) A[i] = a[i], B[i] = b[i];
  for (int i = 0; i <= 0xf; i++) {
    int k = 1 << i;
    for (int j = 0; j <= N - 1; j++)
      if ((j ^ k) > j) {
        (A[j] += A[j ^ k]) %= P;
        (B[j] += B[j ^ k]) %= P;
      }
  }
  for (int i = 0; i <= N - 1; i++) C[i] = A[i] * B[i] % P;
  for (int i = 0; i <= 0xf; i++) {
    int k = 1 << i;
    for (int j = 0; j <= N - 1; j++)
      if ((j ^ k) > j) (C[j] -= C[j ^ k]) %= P;
  }
  for (int i = 0; i <= N - 1; i++) (c[i] += C[i]) %= P;
}
int idx, cnt;
char s[510];
int ch[105][2];
char tag[105];
int init_() {
  int k = ++cnt;
  if (s[idx] == '(') {
    idx++, ch[k][0] = init_(), idx++;
    tag[k] = s[idx++];
    idx++, ch[k][1] = init_(), idx++;
    return k;
  }
  tag[k] = s[idx++];
  return k;
}
long long data[105][N];
void solve(int k) {
  if (ch[k][0] == 0) {
    if (tag[k] == 'A' || tag[k] == '?') data[k][0xff00]++;
    if (tag[k] == 'a' || tag[k] == '?') data[k][0x00ff]++;
    if (tag[k] == 'B' || tag[k] == '?') data[k][0xf0f0]++;
    if (tag[k] == 'b' || tag[k] == '?') data[k][0x0f0f]++;
    if (tag[k] == 'C' || tag[k] == '?') data[k][0xcccc]++;
    if (tag[k] == 'c' || tag[k] == '?') data[k][0x3333]++;
    if (tag[k] == 'D' || tag[k] == '?') data[k][0xaaaa]++;
    if (tag[k] == 'd' || tag[k] == '?') data[k][0x5555]++;
    return;
  }
  solve(ch[k][0]);
  solve(ch[k][1]);
  if (tag[k] == '|' || tag[k] == '?')
    solve0(data[ch[k][0]], data[ch[k][1]], data[k]);
  if (tag[k] == '&' || tag[k] == '?')
    solve1(data[ch[k][0]], data[ch[k][1]], data[k]);
}
int main() {
  scanf("%s", s);
  init_();
  solve(1);
  int n;
  cin >> n;
  vector<pair<int, int> > vec;
  for (int i = 1; i <= n; i++) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int k = a * 8 + b * 4 + c * 2 + d;
    vec.push_back(pair<int, int>(k, e));
  }
  long long ans = 0;
  for (int i = 0; i <= N - 1; i++) {
    int ok = 1;
    for (pair<int, int> x : vec) ok = ok && ((i >> x.first) & 1) == x.second;
    if (ok) (ans += data[1][i]) %= P;
  }
  cout << (ans + P) % P << endl;
  return 0;
}
