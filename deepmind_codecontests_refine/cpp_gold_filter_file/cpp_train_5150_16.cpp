#include <bits/stdc++.h>
using namespace std;
int main(void) {
  double amin, amax;
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
    amin = max(amin, (double)v[i] / (i + 1.0));
    amax = min(amax, (double)(v[i] + 1) / (i + 1.0));
  }
  if (floor(amin * (n + 1)) ==
      (((amax * (n + 1)) - floor(amax * (n + 1))) < 1E-8
           ? floor(amax * (n + 1)) - 1
           : floor(amax * (n + 1)))) {
    cout << "unique" << endl;
    cout << (int)floor(amin * (n + 1));
  } else {
    cout << "not unique";
  }
}
