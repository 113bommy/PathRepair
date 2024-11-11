#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
const int inf = 1034567891;
const long long LL_INF = 1234567890123456789ll;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T>
T GCD(T a, T b) {
  long long t;
  while (a) {
    t = a;
    a = b % a;
    b = t;
  }
  return b;
}
template <typename T>
string toString(T a) {
  return to_string(a);
}
template <typename T>
void toInt(string s, T& x) {
  stringstream str(s);
  str >> x;
}
inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline int mul(int x, int y) { return (x * 1ll * y) % mod; }
inline int powr(int a, long long b) {
  int x = 1 % mod;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a) { return powr(a, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<int> vec;
    int v;
    for (int i = 0; i < n; i++) {
      cin >> v;
      vec.push_back(v);
    }
    vector<vector<int>> cntTotal(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> cntLeft(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        cntTotal[vec[i]][vec[j]]++;
      }
    }
    long long ans = 0;
    vector<int> curCnt(n + 1, 0);
    vector<int> occurrence(n + 1, 0);
    for (int i = 0; i < n; i++) {
      occurrence[vec[i]]++;
    }
    for (int i = 0; i < n; i++) {
      occurrence[vec[i]]--;
      int ai_cnt = curCnt[vec[i]] + 1;
      int cur = 0;
      int x = vec[i];
      vector<int> middleCnt(n + 1, 0);
      middleCnt[vec[i]] += curCnt[vec[i]];
      for (int j = i + 1; j < n; j++) {
        int y = vec[j];
        middleCnt[vec[j]] += ai_cnt;
        ai_cnt += (vec[j] == vec[i]);
        occurrence[vec[j]]--;
        int cur_total = cntTotal[x][y] - cntLeft[x][y] - middleCnt[vec[j]] -
                        ai_cnt * occurrence[y];
        ans += cur_total;
      }
      for (int j = i + 1; j < n; j++) {
        occurrence[vec[j]]++;
      }
      for (int j = 0; j < i; j++) {
        cntLeft[vec[j]][vec[i]]++;
      }
      curCnt[vec[i]]++;
    }
    cout << ans << '\n';
  }
  return 0;
}
