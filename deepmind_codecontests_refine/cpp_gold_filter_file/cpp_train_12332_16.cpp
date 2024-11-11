#include <bits/stdc++.h>
using namespace std;
int x4[] = {0, 0, 1, -1};
int y4[] = {1, -1, 0, 0};
int x8[] = {1, 1, 1, -1, -1, -1, -1, 1};
int y8[] = {0, 1, 0, 1, 0, -1, 0, -1};
bool MBok(int M, int N, int i, int j) {
  if (i >= 0 && j >= 0 && i < M && j < N)
    return 1;
  else
    return 0;
}
void go() {
  int t[5];
  for (int i = 0; i < 5; i++) {
    cin >> t[i];
  }
  string M[5] = {"S", "M", "L", "XL", "XXL"};
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    int j;
    for (j = 0; s != M[j]; j++)
      ;
    int b = -1000;
    for (int k = 0; k < 5; k++) {
      if (t[k] == 0)
        continue;
      else {
        if (abs(b - j) >= abs(k - j)) {
          b = k;
        }
      }
    }
    t[b]--;
    cout << M[b] << endl;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    go();
  }
  return 0;
}
