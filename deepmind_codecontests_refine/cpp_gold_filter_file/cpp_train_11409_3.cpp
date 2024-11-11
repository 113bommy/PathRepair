#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> inp;
vector<long long> v;
long long mat1[100003] = {0};
long long mat2[100003] = {0};
long long my_abs(long long n) {
  if (n < 0) return n * (-1);
  return n;
}
long long my_mx(long long a, long long b) {
  if (a > b) return a;
  return b;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long tmp;
    cin >> tmp;
    inp.push_back(tmp);
  }
  long long mx = -2000000000LL;
  for (int i = 1; i < n; i++) {
    v.push_back(my_abs(inp[i] - inp[i - 1]));
    if (mx < v[i - 1]) {
      mx = v[i - 1];
    }
  }
  long long res = v[0];
  mat1[0] = v[0];
  if (v.size() > 1) {
    if (res < v[1]) {
      res = v[1];
    }
    mat2[1] = v[1];
  }
  long long mul = -1;
  for (long long i = 1, cur = 0; i < v.size(); i++, mul *= (-1)) {
    mat1[i] = my_mx(mat1[i - 1] + mul * v[i], mul * v[i]);
    if (mat1[i] > res) {
      res = mat1[i];
    }
  }
  mul = -1;
  for (long long i = 2, cur = 0; i < v.size(); i++, mul *= (-1)) {
    mat2[i] = my_mx(mat2[i - 1] + mul * v[i], mul * v[i]);
    if (mat2[i] > res) {
      res = mat2[i];
    }
  }
  cout << res << endl;
  return 0;
}
