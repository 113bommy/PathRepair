#include <bits/stdc++.h>
using namespace std;
int A[1000 + 3][1000 + 3];
int f(vector<int> v) {
  int s = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = i; j < v.size(); j += 2) {
      if (j <= v.size() - 1) {
        int l = v[j];
        int r = v[j + 1];
        l--, r--;
        s += A[l][r];
        s += A[r][l];
      }
    }
  }
  return s;
}
int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> A[i][j];
    }
  }
  vector<int> v;
  int maxi = -1;
  for (int i = 0; i < 5; i++) {
    v.push_back(i + 1);
  }
  do {
    if (f(v) > maxi) maxi = f(v);
  } while (next_permutation(v.begin(), v.end()));
  cout << maxi << endl;
  return 0;
}
