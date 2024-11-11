#include <bits/stdc++.h>
using namespace std;
vector<int> A;
vector<int> C;
vector<int> ans;
void tor1(int a) {
  while (a > 0) {
    A.push_back(a % 3);
    a = a / 3;
  }
}
void tor2(int c) {
  while (c > 0) {
    C.push_back(c % 3);
    c = c / 3;
  }
}
long long tor3(vector<int> b) {
  long long an = 0;
  for (int i = 0; i < b.size(); i++) {
    an = an * 3 + b[i];
  }
  return an;
}
int main() {
  int a, c;
  cin >> a >> c;
  tor1(a);
  tor2(c);
  for (int i = 0; i < min(A.size(), C.size()); i++) {
    if (C[i] >= A[i]) {
      ans.push_back(C[i] - A[i]);
    } else {
      ans.push_back(3 - (A[i] - C[i]));
    }
  }
  if (C.size() > A.size()) {
    for (int i = A.size(); i < C.size(); i++) {
      ans.push_back(C[i]);
    }
  } else if (A.size() > C.size()) {
    for (int i = C.size(); i < A.size(); i++) {
      ans.push_back(3 - A[i]);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << tor3(ans);
}
