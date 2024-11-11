#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream second(s);
  string x;
  while (getline(second, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";
  err(++it, args...);
}
int ini() {
  int x;
  scanf("%d", &x);
  return x;
}
long long inl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
double ind() {
  double x;
  scanf("%lf", &x);
  return x;
}
int set_1(int n, int pos) { return n = (n | (1 << pos)); }
int reset_0(int n, int pos) { return n = n & ~(1 << pos); }
bool check_bit(int n, int pos) { return n = n & (1 << pos); }
int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int N = (int)1e6 + 5;
const int M = (int)1e9 + 7;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, te = 0;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    std::vector<int> res;
    for (int i = 0; i + 2 < (int)s.size(); i++) {
      if (i + 4 < s.size()) {
        if (s[i] == 't' and s[i + 1] == 'w' and s[i + 2] == 'o' and
            s[i + 3] == 'n' and s[i + 4] == 'e') {
          res.push_back(i + 2);
          i = i + 4;
          continue;
        }
      }
      if (s[i] == 'o' and s[i + 1] == 'n' and s[i + 2] == 'e') {
        res.push_back(i + 1);
        i = i + 2;
      } else if (s[i] == 't' and s[i + 1] == 'w' and s[i + 2] == 'o') {
        res.push_back(i + 2);
        i = i + 2;
      }
    }
    printf("%d\n", res.size());
    for (auto x : res) printf("%d ", x + 1);
    printf("\n");
  }
  return 0;
}
