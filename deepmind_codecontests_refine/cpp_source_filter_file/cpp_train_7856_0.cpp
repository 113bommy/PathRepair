#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char s[200200];
char s1[200200];
vector<int> p[33];
const double Pi = acos(-1.0);
struct comple {
  double r, i;
  comple(double _r = 0.0, double _i = 0.0) { r = _r, i = _i; }
  comple operator+(const comple &b) { return comple(r + b.r, i + b.i); }
  comple operator-(const comple &b) { return comple(r - b.r, i - b.i); }
  comple operator*(const comple &b) {
    return comple(r * b.r - i * b.i, r * b.i + i * b.r);
  }
};
void change(vector<comple> &y) {
  int ln = y.size();
  for (int i = 1, j = ln >> 1; i < ln - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    int k = ln >> 1;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    j += k;
  }
}
void fft(vector<comple> &y, int on) {
  change(y);
  int len = y.size();
  for (int m = 2; m <= len; m <<= 1) {
    comple wm(cos(-on * 2 * Pi / m), sin(-on * 2 * Pi / m));
    for (int k = 0; k < len; k += m) {
      comple w(1, 0);
      for (int j = 0; j < m / 2; j++) {
        comple u = y[k + j];
        comple t = w * y[k + j + m / 2];
        y[k + j] = u + t;
        y[k + j + m / 2] = u - t;
        w = w * wm;
      }
    }
  }
  if (on == -1)
    for (int i = 0; i < len; i++) y[i].r /= len;
}
vector<int> mult(vector<int> a, vector<int> b) {
  int len = 1;
  int la = a.size();
  int lb = b.size();
  while (len < la + lb) len <<= 1;
  vector<comple> x1(len);
  vector<comple> x2(len);
  for (int i = 0; i < la; i++) x1[i] = comple(a[i], 0);
  for (int i = la; i < len; i++) x1[i] = comple(0, 0);
  for (int i = 0; i < lb; i++) x2[i] = comple(b[i], 0);
  for (int i = lb; i < len; i++) x2[i] = comple(0, 0);
  fft(x1, 1);
  fft(x2, 1);
  for (int i = 0; i < len; i++) x1[i] = x1[i] * x2[i];
  fft(x1, -1);
  vector<int> sol(len);
  for (int i = 0; i < len; i++) {
    sol[i] = x1[i].r + 0.5;
  }
  return sol;
}
int r[1600200];
bool v[33];
int main() {
  cin >> n >> m >> k;
  scanf("%s", s);
  scanf("%s", s1);
  for (int i = 0; i < n; i++) {
    p[s[i] - 'A'].push_back(i);
  }
  v['A' - 'A'] = 1;
  v['C' - 'A'] = 1;
  v['G' - 'A'] = 1;
  v['T' - 'A'] = 1;
  for (int c = 0; c < 26; c++) {
    if (!v[c]) continue;
    int j = 0;
    vector<int> a;
    vector<int> b;
    int r1 = 0;
    for (int i = 0; i < 2 * n; i++) {
      while (j < p[c].size() && i - p[c][j] > k) j++;
      if (j < p[c].size() && abs(i - p[c][j]) <= k)
        a.push_back(1);
      else
        a.push_back(0);
    }
    int l = 0;
    for (int i = 0; i < m; i++) {
      b.push_back(s1[i] == c + 'A');
      r1 += s1[i] == c + 'A';
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++)
      if (b[i]) l = i;
    a = mult(a, b);
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == r1) {
        r[(i)]++;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < 2 * n; i++) res += r[i] == 4;
  cout << res << endl;
  return 0;
}
