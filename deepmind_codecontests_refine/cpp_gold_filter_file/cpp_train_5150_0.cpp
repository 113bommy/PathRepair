#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long double amin, amax;
  int n;
  vector<int> v;
  cin >> n;
  for (int i = (0); i < ((n)); ++i) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  amin = v[0];
  amax = v[0] + 1;
  for (int i = (1); i < (n); ++i) {
    amin = max(amin, (long double)v[i] / (i + 1.0));
    amax = min(amax, (long double)(v[i] + 1) / (i + 1.0));
  }
  long double expect_min(amin * (n + 1) + 1e-10);
  long double expect_max(amax * (n + 1) - 1e-10);
  if ((int)floor(expect_min) == (int)floor(expect_max)) {
    cout << "unique" << endl;
    cout << (int)floor(expect_min);
  } else {
    cout << "not unique";
  }
}
