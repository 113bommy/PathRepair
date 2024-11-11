#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
using ll = i64;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using matrix = vector<vector<T> >;
template <class T>
inline string toString(const vector<T>& x) {
  stringstream ss;
  for (int i = 0; i < (int)(x.size()); ++i) {
    if (i != 0) ss << " ";
    ss << x[i];
  }
  return ss.str();
}
template <class T>
inline string toString(const vector<vector<T> >& map) {
  stringstream ss;
  for (int i = 0; i < (int)(map.size()); ++i) {
    if (i != 0) ss << "\n";
    ss << toString(map[i]);
  }
  return ss.str();
}
template <class K, class V>
string toString(map<K, V>& x) {
  string res;
  stringstream ss;
  for (auto& p : x) ss << p.first << ":" << p.second << " ";
  return ss.str();
}
string BITtoString(int bit) {
  stringstream ss;
  while (bit != 0) {
    ss << (bit % 2);
    bit /= 2;
  }
  string res = ss.str();
  reverse((res).begin(), (res).end());
  return res;
}
template <typename T, typename V>
inline T mod(T v, V MOD) {
  return (v % MOD + MOD) % MOD;
}
const ll MOD = 1000000007;
int INF = 1 << 28;
class Main {
 public:
  void run() {
    double x;
    cin >> x;
    for (int a = 1; a <= 10; a++)
      for (int h = a + 1; h <= 10; h++) {
        double v =
            (double)a * h / (2 * sqrt((double)a * a + (double)h * h / 4));
        if (abs(v - x) < 1e-3) {
          cout << h << " " << a << endl;
          return;
        }
      }
  }
};
int main() {
  ios::sync_with_stdio(false);
  Main().run();
  return 0;
}
