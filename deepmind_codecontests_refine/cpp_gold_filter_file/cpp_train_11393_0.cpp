#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int a, b, c, d, i, j, n, m, k, h, m2, m1, m0;
string s;
int pp12[601], ppp12[601];
vector<string> ret(0);
inline vector<int> operator+(const vector<int> &a, const vector<int> &b) {
  vector<int> ans(0);
  for (int _n((max((int)((a).size()), (int)((b).size()))) - 1), i(0); i <= _n;
       i++) {
    int t = 0;
    if (i < (int)((ans).size())) t += ans[i];
    if (i < (int)((a).size())) t += a[i];
    if (i < (int)((b).size())) t += b[i];
    if (i >= (int)((ans).size())) ans.push_back(0);
    ans[i] = t % 100;
    if (i + 1 >= (int)((ans).size())) ans.push_back(0);
    ans[i + 1] = t / 100;
  }
  if ((int)((ans).size()) && ans.back() >= 100) {
    ans.push_back(ans[(int)((ans).size()) - 1] / 100);
    ans[(int)((ans).size()) - 2] %= 100;
  }
  while ((int)((ans).size()) && ans.back() == 0) ans.pop_back();
  return ans;
}
inline vector<int> operator*(const vector<int> &a, int b) {
  vector<int> ans(0);
  for (int _n(((int)((a).size())) - 1), i(0); i <= _n; i++) {
    if (i >= (int)((ans).size())) ans.push_back(0);
    int t = ans[i] + a[i] * b;
    ans[i] = t % 100;
    if (i + 1 >= (int)((ans).size())) ans.push_back(0);
    ans[i + 1] = t / 100;
  }
  if ((int)((ans).size()) && ans.back() >= 100) {
    ans.push_back(ans[(int)((ans).size()) - 1] / 100);
    ans[(int)((ans).size()) - 2] %= 100;
  }
  while ((int)((ans).size()) && ans.back() == 0) ans.pop_back();
  return ans;
}
inline vector<int> p12(int n) {
  vector<int> p(1, 1);
  for (int _n((n)-1), h(0); h <= _n; h++) {
    p = p * 12;
  }
  return p;
}
inline string str(const vector<int> &a) {
  ostringstream oss;
  if (!(int)((a).size())) oss << 0;
  for (int i = ((int)((a).size()) - 1), _b = (0); i >= _b; i--) {
    if (i == (int)((a).size()) - 1)
      oss << a[i];
    else if (a[i] < 10)
      oss << 0 << a[i];
    else
      oss << a[i];
  }
  return oss.str();
}
inline bool cmp(const string &s1, const string &s2) {
  if ((int)((s1).size()) != (int)((s2).size()))
    return (int)((s1).size()) < (int)((s2).size());
  else
    return s1 < s2;
}
int main() {
  cin >> s;
  pp12[0] = 1;
  ppp12[0] = 1;
  for (int _n((600)), i(1); i <= _n; i++)
    pp12[i] = ((long long)pp12[i - 1] * 12) % 1000000007,
    ppp12[i] = ((long long)ppp12[i - 1] * 12) % 1000000009;
  h = 0;
  int h2 = 0;
  for (int _n(((int)((s).size())) - 1), i(0); i <= _n; i++)
    h = ((long long)h * 10 + s[i] - '0') % 1000000007,
    h2 = ((long long)h2 * 10 + s[i] - '0') % 1000000009;
  if (s == "2") {
    printf("YES\n");
    printf("1\n");
    printf("1\n");
    printf("0\n");
    exit(0);
  } else if (s == "13") {
    printf("YES\n");
    printf("1\n");
    printf("2\n");
    printf("0\n");
    exit(0);
  }
  for (int _n(600), hh(3); hh <= _n; hh++) {
    bool found = 0;
    for (int _n((hh - 1) - 1), i(0); i <= _n; i++) {
      if (h == (pp12[i] + pp12[hh - i - 1]) % 1000000007 &&
          h2 == (ppp12[i] + ppp12[hh - i - 1]) % 1000000009) {
        found = 1;
        break;
      }
    }
    if (found) {
      printf("YES\n");
      printf("1\n");
      printf("%d\n", hh);
      for (int _n((hh - 1) - 1), i(0); i <= _n; i++) {
        ret.push_back(str(p12(i) + p12(hh - i - 1)));
      }
      sort((ret).begin(), (ret).end());
      ret.resize(unique((ret).begin(), (ret).end()) - ret.begin());
      sort((ret).begin(), (ret).end(), cmp);
      printf("%d\n", (int)((ret).size()) - 1);
      for (int _n(((int)((ret).size())) - 1), i(0); i <= _n; i++) {
        if (ret[i] != s) printf("%s\n", ret[i].c_str());
      }
      exit(0);
    }
  }
  printf("NO\n");
}
