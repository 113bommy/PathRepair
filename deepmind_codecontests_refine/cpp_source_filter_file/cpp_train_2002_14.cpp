#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1.0);
int popcount(int n) { return __builtin_popcount(n); }
int popcount(long long n) { return __builtin_popcountll(n); }
template <class T>
int SIZE(T a) {
  return a.size();
}
template <class T>
string IntToString(T num) {
  string res;
  stringstream ss;
  ss << num;
  return ss.str();
}
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
void PrintSeq(T &a, int sz) {
  for (int i = 0; i < sz; i++) {
    cout << a[i];
    if (sz == i + 1)
      cout << endl;
    else
      cout << ' ';
  }
}
bool EQ(double a, double b) { return abs(a - b) < EPS; }
void fastStream() {
  cin.tie(0);
  std::ios_base::sync_with_stdio(0);
}
vector<string> split(string str, char del) {
  vector<string> res;
  for (int i = 0, s = 0; i < SIZE(str); i++) {
    if (str[i] == del) {
      if (i - s != 0) res.push_back(str.substr(s, i - s));
      s = i + 1;
    } else if (i == SIZE(str) - 1) {
      res.push_back(str.substr(s));
    }
  }
  return res;
}
int H, W, K;
char field[501][501];
bool downFound[501][501];
bool rightFound[501][501];
int xSums[501][501];
int ySums[501][501];
const int dy[] = {0, -1, 0, 1, 0}, dx[] = {0, 0, 1, 0, -1};
bool foundStar(int cy, int cx) {
  for (int i = 0; i < 5; i++) {
    int ny = cy + dy[i];
    int nx = cx + dx[i];
    if (!(ny >= 0 && nx >= 0 && ny < H && nx < W && field[ny][nx] == '1'))
      return false;
  }
  return true;
}
int main() {
  cin >> H >> W >> K;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) cin >> field[i][j];
  for (int i = 0; i < H; i++)
    for (int j = 2; j < W; j++) rightFound[i][j] = (foundStar(i, j - 1));
  for (int i = 2; i < H; i++)
    for (int j = 0; j < W; j++) downFound[i][j] = (foundStar(i - 1, j));
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) xSums[i][j + 1] = xSums[i][j] + downFound[i][j];
  for (int j = 0; j < W; j++)
    for (int i = 0; i < H; i++)
      ySums[i + 1][j] = ySums[i][j] + rightFound[i][j];
  int res = 0;
  for (int miny = 0; miny < H; miny++) {
    for (int minx = 0; minx < W; minx++) {
      int maxy = miny + 1;
      int cnt = 0;
      for (int maxx = W - 1; maxx >= minx + 2; maxx--) {
        while (maxy < H && cnt < K) {
          maxy++;
          cnt += xSums[maxy][maxx] - xSums[maxy][minx + 1];
        }
        if (maxy == H) {
          if (cnt >= K) res++;
        } else
          res += (H - maxy);
        cnt -= ySums[maxy][maxx] - ySums[miny + 1][maxx];
      }
    }
  }
  cout << res << endl;
  return 0;
}
