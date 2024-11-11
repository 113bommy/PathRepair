#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
string to_str(T str) {
  stringstream stream;
  stream << str;
  return stream.str();
}
template <typename T>
int to_int(T num) {
  int val;
  stringstream stream;
  stream << num;
  stream >> val;
  return val;
}
vector<string> split(const string& s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) elems.push_back(item);
  return elems;
}
const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int T2 = 105;
const int T3 = 1005;
const int T4 = 10005;
const int T5 = 100005;
int p[T5], t[T5], s1[T5], s2[T5];
int main() {
  ios_base::sync_with_stdio(0);
  int n, c;
  cin >> n >> c;
  long long int ans1 = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) {
    s1[i] = t[i] + s1[i - 1];
    ans1 += max(0, p[i] - c * s1[i]);
  }
  for (int i = n; i >= 1; i--) {
    s2[i] = t[i] + s2[i + 1];
    ans2 += max(0, p[i] - c * s2[i]);
  }
  if (ans1 == ans2)
    cout << "Tie\n";
  else if (ans1 > ans2)
    cout << "Limark\n";
  else
    cout << "Radewoosh\n";
  return 0;
}
