#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
long long extended(long long a, long long b, long long &x, long long &y) {
  a = abs(a);
  b = abs(b);
  long long g, x1, y1;
  if (!b) {
    x = 1;
    y = 0;
    g = a;
    return g;
  }
  g = extended(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
long long modinverse(long long a, long long M) { return bigmod(a, M - 2, M); }
long long bpow(long long p, long long e) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return ret;
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int toLlint(string s) {
  long long int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
string convertInt(long long number) {
  if (number == 0) return "0";
  string temp = "";
  string returnvalue = "";
  while (number > 0) {
    temp += number % 10 + 48;
    number /= 10;
  }
  for (int i = 0; i < temp.length(); i++)
    returnvalue += temp[temp.length() - i - 1];
  return returnvalue;
}
long long ncr[1001][1001];
void NCR() {
  for (int i = 1; i <= 1000; i++) {
    ncr[i][i] = 1;
    ncr[i][0] = 1;
    for (int r = 1; r < i; r++) {
      ncr[i][r] = (ncr[i - 1][r] + ncr[i - 1][r - 1]) % 1000000007;
    }
  }
}
vector<int> vec[4002];
int ar[4001][4001];
pair<int, int> p[4002];
int main() {
  int n, m;
  cin >> n >> m;
  int x1, x2;
  for (int i = 0; i < m; i++) {
    cin >> x1 >> x2;
    p[i].first = x1;
    p[i].second = x2;
    ar[x1][x2] = 1;
    ar[x2][x1] = 1;
    vec[x1].push_back(x2);
    vec[x2].push_back(x1);
  }
  int mini = 100000000, ans;
  int flag = 0;
  for (int i = 0; i < m; i++) {
    int fs, sn, td;
    fs = p[i].first;
    sn = p[i].second;
    for (int j = i + 1; j < m; j++) {
      if (p[j].first == sn) {
        td = p[j].second;
        if (ar[td][fs] == 1) {
          flag = 1;
          ans = vec[fs].size();
          ans += vec[sn].size();
          ans += vec[td].size();
          ans = ans - 6;
          mini = min(ans, mini);
        }
      }
    }
  }
  if (flag == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << mini << endl;
  return 0;
}
