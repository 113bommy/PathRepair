#include <bits/stdc++.h>
using namespace std;
template <typename T>
T absll(T X) {
  if (X < 0)
    return -1 * X;
  else
    return X;
}
int main() {
  int N;
  cin >> N;
  string str;
  cin >> str;
  int maxsteps = -1;
  int steps = 0;
  vector<int> V(10000, 0);
  vector<int> A;
  for (int i = 0; i < N; i++) {
    if (str[i] == '*') {
      V[i + 1] = 1;
      A.push_back(i);
    }
  }
  bool flag = 1;
  for (int i = 0; i < A.size(); i++) {
    for (int j = 1; j <= 100; j++) {
      flag = 1;
      for (int k = 1; k < 5; k++) {
        if (V[A[i] + k * j] == 0) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        cout << "yes\n";
        return 0;
      }
    }
  }
  printf("no\n");
  return 0;
}
