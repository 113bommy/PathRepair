#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int max(int a, int b) { return (a >= b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
int main() {
  int n;
  cin >> n;
  int* Array = new int[n];
  for (int i = 0; i < n; i++) cin >> Array[i];
  int Res = Array[n - 1] - Array[0];
  for (int i = 1; i < n - 1; i++) {
    int tmp = 0;
    for (int j = 1; j < n - 1; j++) {
      if (j == i) {
        tmp = max(tmp, Array[j + 1] - Array[j - 1]);
        j++;
      } else
        tmp = max(tmp, Array[j] - Array[j - 1]);
    }
    Res = min(Res, tmp);
  }
  cout << Res;
  return 0;
}
