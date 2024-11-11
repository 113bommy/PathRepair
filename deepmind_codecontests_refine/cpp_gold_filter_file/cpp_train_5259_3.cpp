#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926536;
int dX[] = {1, -1, 0, 0};
int dY[] = {0, 0, 1, -1};
int main() {
  int n, idx, mx = 0, arr[100002] = {};
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &idx);
    arr[idx] = arr[idx - 1] + 1;
    mx = max(arr[idx], mx);
  }
  cout << n - mx;
}
