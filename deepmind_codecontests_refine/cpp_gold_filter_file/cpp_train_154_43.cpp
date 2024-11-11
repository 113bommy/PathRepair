#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long double x, y, z, ans = -1 * (1e9);
string out[12] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                  "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                  "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> x >> y >> z;
  int pos = -1;
  if (log(x) * pow(y, z) > ans) {
    ans = log(x) * pow(y, z);
    pos = 0;
  }
  if (log(x) * pow(z, y) > ans) {
    ans = log(x) * pow(z, y);
    pos = 1;
  }
  if (log(x) * y * z > ans) {
    ans = log(x) * y * z;
    pos = 2;
  }
  if (log(x) * z * y > ans) {
    ans = log(x) * z * y;
    pos = 2;
  }
  if (log(y) * pow(x, z) > ans) {
    ans = log(y) * pow(x, z);
    pos = 4;
  }
  if (log(y) * pow(z, x) > ans) {
    ans = log(y) * pow(z, x);
    pos = 5;
  }
  if (log(y) * x * z > ans) {
    ans = log(y) * x * z;
    pos = 6;
  }
  if (log(y) * x * z > ans) {
    ans = log(y) * x * z;
    pos = 6;
  }
  if (log(z) * pow(x, y) > ans) {
    ans = log(z) * pow(x, y);
    pos = 8;
  }
  if (log(z) * pow(y, x) > ans) {
    ans = log(z) * pow(y, x);
    pos = 9;
  }
  if (log(z) * x * y > ans) {
    ans = log(y) * x * y;
    pos = 10;
  }
  if (log(z) * x * y > ans) {
    ans = log(y) * x * y;
    pos = 10;
  }
  cout << out[pos] << endl;
  return 0;
}
