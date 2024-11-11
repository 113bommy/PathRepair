#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  string X;
  int size;
  int best = 0;
  int k;
  bool flag = false;
  for (int i = 0; i < N; i++) {
    cin >> size;
    cin >> X;
    for (int j = 0; j < size; j++)
      if (X[j] == '1') {
        best = max(best, max(abs(j - 0), abs(j - size)));
        flag = true;
      }
    if (flag)
      cout << best * 2 << "\n";
    else
      cout << size << " \n";
    best = 0;
    flag = false;
  }
  return 0;
}
