#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;
    arr.push_back(h * 60 + m);
  }
  if (arr[0] > s) {
    printf("0 0\n");
    return 0;
  }
  int df = s * 2 + 2;
  int i = 0;
  while (i < arr.size() - 1) {
    if (arr[i + 1] - arr[i] >= df) {
      break;
    }
    i++;
  }
  int ans = arr[i] + s + 1;
  printf("%d %d\n", ans / 60, ans % 60);
}
