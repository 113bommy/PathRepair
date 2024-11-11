#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
int gi() {
  int i;
  cin >> i;
  return i;
}
long long gl() {
  long long i;
  cin >> i;
  return i;
}
namespace {
const long long MOD7 = 1000000007LL, MOD9 = 1000000007LL;
enum class START_OPTION {
  NOTHING = 0,
  FILE_INPUT = 1,
  FILE_OUTPUT = (1 << 1),
  FILE_OUTHERE = (1 << 2)
};
inline START_OPTION operator|(START_OPTION a, START_OPTION b) {
  return static_cast<START_OPTION>(static_cast<int>(a) | static_cast<int>(b));
}
inline int operator&(START_OPTION a, START_OPTION b) {
  return static_cast<int>(a) & static_cast<int>(b);
}
template <typename T1, typename T2>
istream& operator>>(istream& i, pair<T1, T2>& p) {
  return i >> p.first >> p.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& i, pair<T1, T2>& p) {
  return i << p.first << " " << p.second;
}
template <typename T>
istream& operator>>(istream& i, vector<T>& v) {
  for (auto& e : v) i >> e;
  return i;
}
template <typename T>
ostream& operator<<(ostream& i, vector<T>& v) {
  for (size_t ii = 0; ii < v.size(); ii++) {
    i << v[ii];
    if (ii + 1 != v.size()) i << ' ';
  }
  return i;
}
void _start(START_OPTION opt = START_OPTION::NOTHING,
            string fileIn = "input.txt", string fileOut = "output.txt") {
  if ((opt & START_OPTION::FILE_OUTHERE) && (opt & START_OPTION::FILE_INPUT))
    freopen(fileIn.c_str(), "r", stdin);
  if ((opt & START_OPTION::FILE_OUTHERE) && (opt & START_OPTION::FILE_OUTPUT))
    freopen(fileOut.c_str(), "w", stdout);
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(0);
}
template <typename T = string>
void _end(T out = "", int returnValue = 0) {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  cout << out;
  exit(returnValue);
}
}  // namespace
int main() {
  _start(START_OPTION::FILE_INPUT);
  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  int mx0 = 0, mx1 = 0;
  for (int i = 0; i < int(n); i++) {
    if (v[i] == 0)
      mx0 = i;
    else
      mx1 = i;
  }
  _end(min(mx0, mx1) + 1);
}
