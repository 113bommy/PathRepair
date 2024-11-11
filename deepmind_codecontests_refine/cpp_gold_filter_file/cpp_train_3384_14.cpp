#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T sqr(T x) {
  return x * x;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < (n); ++i) {
    cin >> v[i];
  }
  int step = -1;
  vector<int> p = v;
  const int MAXSTEP = 171;
  bool ok = false;
  while (step < MAXSTEP) {
    ++step;
    for (int i = 1; i < n - 1; ++i) {
      p[i] = (v[i - 1] + v[i] + v[i + 1]) >> 1;
    }
    if (v == p) {
      ok = true;
      break;
    }
    swap(v, p);
  }
  if (!ok) {
    vector<int> res = v;
    int plusStep = 0;
    for (int i = 0; i < (n - 1); ++i) {
      int start = i + 1;
      while (i < n - 1 && v[i] != v[i + 1]) {
        ++i;
      }
      if (i > start + 1) {
        int finish = i - 1;
        int l = finish - start + 1;
        plusStep = max(plusStep, (l + 1) / 2);
        while (start <= finish) {
          res[start] = res[start - 1];
          res[finish] = res[finish + 1];
          ++start;
          --finish;
        }
      }
    }
    step += plusStep + 1;
    swap(v, res);
  }
  cout << step << endl;
  for (int i = 0; i < (n); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
