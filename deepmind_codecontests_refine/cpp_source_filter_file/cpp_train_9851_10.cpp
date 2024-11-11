#include <bits/stdc++.h>
using namespace std;
long long readi() {
  long long input = 0;
  char c = ' ';
  while (c < '-') {
    c = getchar();
  }
  bool negative = false;
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  while (c >= '0') {
    input = 10 * input + (c - '0');
    c = getchar();
  }
  if (negative) {
    input = -input;
  }
  return input;
}
void printi(long long output) {
  if (output == 0) {
    putchar('0');
    return;
  }
  if (output < 0) {
    putchar('-');
    output = -output;
  }
  int aout[20];
  int ilen = 0;
  while (output) {
    aout[ilen] = ((output % 10));
    output /= 10;
    ilen++;
  }
  for (int i = ilen - 1; i >= 0; i--) {
    putchar(aout[i] + '0');
  }
  return;
}
string reads() {
  string input = "";
  char c = ' ';
  while (c <= ' ') {
    c = getchar();
  }
  while (c > ' ') {
    input += c;
    c = getchar();
  }
  return input;
}
void prints(string output) {
  for (int i = 0; i < output.length(); i++) {
    putchar(output[i]);
  }
  return;
}
int N;
pair<int, int> coor[200010];
map<int, int> compress;
vector<int> pts[200010];
int64_t pw2[200010];
int parent[200010];
int edge[200010], vert[200010];
int64_t ans = 1ll;
int fpar(int u) {
  if (u == parent[u]) {
    return u;
  }
  parent[u] = fpar(parent[u]);
  return parent[u];
}
void merge(int u, int v) {
  u = fpar(u);
  v = fpar(v);
  if (u == v) {
    return;
  }
  parent[u] = v;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  srand(time(NULL));
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> coor[i].first >> coor[i].second;
  }
  pw2[0] = 1;
  for (int i = 1; i <= N; i++) {
    pw2[i] = pw2[i - 1] * 2;
    pw2[i] %= 1000000007;
  }
  for (int i = 0; i < N; i++) {
    compress[coor[i].first] = 1;
  }
  int spam = 0;
  for (auto it = compress.begin(); it != compress.end(); it++) {
    it->second = spam;
    spam++;
  }
  for (int i = 0; i < N; i++) {
    coor[i].first = compress[coor[i].first];
  }
  compress.clear();
  for (int i = 0; i < N; i++) {
    compress[coor[i].second] = 1;
  }
  spam = 0;
  for (auto it = compress.begin(); it != compress.end(); it++) {
    it->second = spam;
    spam++;
  }
  for (int i = 0; i < N; i++) {
    coor[i].second = compress[coor[i].second];
  }
  for (int i = 0; i < N; i++) {
    pts[coor[i].first].push_back(coor[i].second + N);
  }
  for (int i = 0; i < 2 * N; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < pts[i].size(); j++) {
      merge(i, pts[i][j]);
    }
  }
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < pts[i].size(); j++) {
      edge[fpar(i)]++;
    }
    vert[fpar(i)]++;
  }
  for (int i = 0; i < 2 * N; i++) {
    if (edge[i] == vert[i] - 1) {
      ans *= (pw2[vert[i]] - 1);
    } else {
      ans *= pw2[vert[i]];
    }
    ans %= 1000000007;
  }
  cout << ans << '\n';
  return 0;
}
