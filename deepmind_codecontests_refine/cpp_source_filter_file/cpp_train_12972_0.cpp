#include <bits/stdc++.h>
using namespace std;
string i_s(int x) {
  if (x == 0) return "0";
  string ret = "";
  while (x) {
    ret = ret + (char)(x % 10 + '0');
    x /= 10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
string add(string a, string b) {
  if (a == "") a = "0";
  if (b == "") b = "0";
  if (a.length() < b.length()) swap(a, b);
  while (b.length() < a.length()) {
    b = '0' + b;
  }
  for (int i = 0; i < a.length(); i++) {
    a[i] = a[i] + (b[i] - '0');
  }
  bool big = false;
  for (int i = a.length() - 1; i >= 0; i--) {
    if (big) {
      a[i]++;
    }
    big = false;
    if (a[i] > '9') {
      a[i] = a[i] - 10;
      big = true;
    }
  }
  if (big) a = '1' + a;
  return a;
}
string mul(string a, string b) {
  vector<int> va, vb;
  if (a == "0" || b == "0") return "0";
  string ans;
  for (int i = 0; i < a.length(); i++) {
    va.push_back(a[i] - '0');
  }
  for (int i = 0; i < b.length(); i++) {
    vb.push_back(b[i] - '0');
  }
  reverse(va.begin(), va.end());
  reverse(vb.begin(), vb.end());
  vector<int> res;
  res.clear();
  res.resize(1005);
  for (int i = 0; i < a.length(); i++) {
    for (int j = 0; j < b.length(); j++) {
      res[i + j] += (va[i] * vb[j]);
    }
  }
  for (int i = 0; i < 1005; i++) {
    if (res[i] > 9) {
      res[i + 1] += (res[i] / 10);
      res[i] %= 10;
    }
  }
  for (int i = 0; i < 1005; i++) {
    ans += (res[i] + '0');
  }
  reverse(ans.begin(), ans.end());
  int k = 0;
  while (ans[k] == '0') {
    k++;
  }
  ans = ans.substr(k);
  return ans;
}
bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
vector<int> x, y;
int n;
double dist(int i, int j) {
  return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
double dpl[3000][3000];
double dpr[3000][3000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    x.push_back(a);
    y.push_back(b);
    dpl[i][i] = 0;
    dpr[i][i] = 0;
  }
  double ans = 0;
  for (int k = 1; k <= n - 1; k++) {
    for (int i = 0; i < n; i++) {
      int j = (i + k) % n;
      dpl[i][j] = max(dpl[(i + 1) % n][j] + dist(i, (i + 1) % n),
                      dpr[(i + 1) % n][j] + dist(i, j));
      dpr[i][j] = max(dpr[i][(j + n - 1) % n] + dist((j + n - 1) % n, j),
                      dpl[i][(j + n - 1) % n] + dist(i, j));
      ans = max(ans, dpl[i][j]);
      ans = max(ans, dpr[i][j]);
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
