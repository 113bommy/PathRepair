#include <bits/stdc++.h>
using namespace std;
struct fastIO {
  inline fastIO operator>>(int& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(long long& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(float& num) {
    scanf("%f", &num);
    return *this;
  }
  inline fastIO operator>>(double& num) {
    scanf("%lf", &num);
    return *this;
  }
  inline fastIO operator>>(long double& num) {
    scanf("%Lf", &num);
    return *this;
  }
  inline fastIO operator>>(char& num) {
    num = getchar();
    while (num == ' ' || num == '\n') num = getchar();
    return *this;
  }
  inline fastIO operator>>(char* num) {
    int cnt = 0;
    char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    while (c != ' ' && c != '\n') {
      num[cnt++] = c;
      c = getchar();
    }
    num[cnt] = 0;
    return *this;
  }
  inline fastIO operator>>(string& num) {
    cin >> num;
    return *this;
  }
  inline void printInt(const int& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printInt(num / 10);
    putchar((num % 10) + '0');
  }
  inline void printINT(const long long& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printINT(num / 10);
    putchar((num % 10) + '0');
  }
  inline fastIO operator<<(const int& num) {
    if (num < 0)
      putchar('-'), printInt(-num);
    else
      printInt(num);
    return *this;
  }
  inline fastIO operator<<(const long long& num) {
    if (num < 0)
      putchar('-'), printINT(-num);
    else
      printINT(num);
    return *this;
  }
  inline fastIO operator<<(const float& num) {
    printf("%.10f", num);
    return *this;
  }
  inline fastIO operator<<(const double& num) {
    printf("%.16lf", num);
    return *this;
  }
  inline fastIO operator<<(const long double& num) {
    printf("%.20Lf", num);
    return *this;
  }
  inline fastIO operator<<(const char& num) {
    putchar(num);
    return *this;
  }
  inline fastIO operator<<(const char* num) {
    for (int i = 0; num[i]; i++) putchar(num[i]);
    return *this;
  }
  inline fastIO operator<<(const string& num) {
    cout << num;
    return *this;
  }
} fio;
bool lesseq(double a, double b) { return a < b + 1e-15; }
struct ConvexHull {
  vector<pair<double, double> > lns;
  void init() { lns.clear(); }
  bool fuck(int a, int b, int c) {
    return lesseq(
        (lns[c].second - lns[a].second) * (lns[a].first - lns[b].first),
        (lns[b].second - lns[a].second) * (lns[a].first - lns[c].first));
  }
  void ins(double a, double b) {
    lns.push_back(make_pair(a, b));
    while (((int)(lns).size()) >= 3 &&
           fuck(((int)(lns).size()) - 3, ((int)(lns).size()) - 2,
                ((int)(lns).size()) - 1)) {
      lns[((int)(lns).size()) - 2] = lns[((int)(lns).size()) - 1];
      lns.pop_back();
    }
  }
  double get(int whr, double x) { return lns[whr].first * x + lns[whr].second; }
  double find(double num) {
    int l = 0, r = ((int)(lns).size()) - 1;
    while (r > l) {
      int m = (l + r) >> 1;
      if (lesseq(get(m + 1, num), get(m, num))) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return get(l, num);
  }
} cvx;
double dp[55][200005];
long long t[200005], sum[200005];
double fsum[200005], pre[200005];
int n, k;
int main() {
  fio >> n >> k;
  for (int i = 1; i <= n; i++) {
    fio >> t[i];
    sum[i] = sum[i - 1] + t[i];
    fsum[i] = fsum[i - 1] + 1.0 / t[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + sum[i] * 1.00 / t[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[0][i] = ((long long)0x3f3f3f3f3f3f3f3f);
  }
  for (int i = 1; i <= k; i++) {
    cvx.init();
    cvx.ins(0, 0);
    for (int j = 1; j <= n; j++) {
      dp[i][j] = cvx.find(fsum[j]) + pre[j];
      cvx.ins(-sum[j], dp[i - 1][j] - pre[j] + sum[j] * fsum[j]);
    }
  }
  fio << dp[k][n] << '\n';
  return 0;
}
