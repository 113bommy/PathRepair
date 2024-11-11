#include <bits/stdc++.h>
using namespace std;
template <typename type>
type input() {
  type var;
  cin >> var;
  return var;
}
template <typename type>
void input(type &var) {
  cin >> var;
  return;
}
template <typename type>
void output(type &var, const char *ch) {
  cout << var << ch;
}
int lower(vector<long long> &v, int M) {
  int e = v.size() - 1, s = 0, mid = (s + e) / 2;
  while (e >= s) {
    if (v[mid] > M) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
    mid = (s + e) / 2;
  }
  return e + 1;
}
int main() {
  int N, M, p = 1, m = 0;
  string A = "", B = "";
  do {
    B += A;
    A = "";
    cin >> A;
    if (A == "+")
      ++p;
    else if (A == "-")
      ++m;
  } while (A != "=");
  cin >> N;
  long long a, b, c, d, R;
  if (p * N - m < N || p - N * m > N)
    cout << "Impossible" << endl;
  else {
    cout << "Possible" << endl;
    vector<long long> v(p, 1), w(m, 1);
    int i = 0;
    R = N - p + m;
    if (R < 0) {
      i = 0;
      while (R < 0 && i < w.size()) {
        a = w[i];
        b = N - a;
        if (R + b >= 0)
          b = -R, R = 0;
        else
          R += b;
        w[i] += b;
        ++i;
      }
    } else {
      i = 0;
      while (R > 0 && i < v.size()) {
        a = v[i];
        b = N - a;
        if (b >= R)
          b = R, R = 0;
        else
          R -= b;
        v[i] += b;
        ++i;
      }
    }
    cout << v[0] << " ";
    int kk = 1, ss = 0;
    for (int xy = 1; xy < B.size(); xy += 2) {
      if (B[xy] == '+')
        cout << "+ " << v[kk++] << " ";
      else
        cout << "- " << w[ss++] << " ";
    }
    cout << "= " << N << endl;
  }
  return 0;
}
