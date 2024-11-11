#include <bits/stdc++.h>
using namespace std;
void prime_vector(vector<int>& P) {
  P.push_back(2);
  bool ip;
  for (int X = 3; X <= 1555; X += 2) {
    ip = true;
    for (int i = 0; P[i] * P[i] <= X && ip; ++i) ip = (bool)(X % P[i]);
    if (ip) P.push_back(X);
  }
}
int main() {
  string S, R = "@";
  vector<int> P, C;
  prime_vector(P);
  int K = 1;
  getline(cin, S);
  C.assign(26, 0);
  for (int i = 0; i < S.size(); ++i) ++C.at(S.at(i) - 'a');
  for (int j = 0, p = P.at(0), L = S.size(); p <= L; p = P.at(++j)) {
    K += (int)(p * 2 > L);
  }
  int mcount = 0;
  char Z = '#';
  for (int i = 0; i < 26; ++i)
    if (C.at(i) > mcount) {
      mcount = C.at(i);
      Z = i + 'a';
    }
  if (mcount < S.size() - K) {
    cout << "NO" << endl;
    return 0;
  } else {
    C.at(Z - 'a') -= S.size() - K;
  }
  int j = 0;
  for (int i = 1, p = P.at(j); i < S.size(); ++i) {
    if (i >= P.at(j)) p = P.at(++j);
    if (i + 1 == p && p * 2 > S.size()) {
      R += '@';
    } else {
      R += Z;
    }
  }
  cout << "YES" << endl;
  int z = 0;
  for (int i = 0; i < R.size(); ++i) {
    if (R.at(i) == '@') {
      while (C.at(z) <= 0) ++z;
      R.at(i) = z + 'a';
      --C.at(z);
    }
  }
  cout << R << endl;
  return 0;
}
