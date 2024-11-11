#include <bits/stdc++.h>
using namespace std;
void func(int a, int b, int x, int y, int arr[]) {
  arr[0] = a * y;
  arr[1] = a * (b - y - 1);
  arr[2] = b * (a - x - 1);
  arr[3] = b * x;
}
int main() {
  int cases, a, b, x, y, results[10000], arr[4];
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> a >> b >> x >> y;
    func(a, b, x, y, arr);
    int max = 0;
    for (int j = 0; j < 4; j++) {
      if (max < arr[j]) max = arr[j];
    }
    results[i] = max;
  }
  for (int i = 0; i < cases; i++) cout << results[i];
}
