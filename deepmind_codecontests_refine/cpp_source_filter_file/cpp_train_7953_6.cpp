#include <bits/stdc++.h>
using namespace std;
int n, a[1000010];
void GetData() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) a[i] *= -1;
  }
}
void Run() {
  int res = 0, b, c;
  for (int i = 0; i < n; i++) {
    b = c = 0;
    for (int j = 0; j < n; j++) {
      if (a[i] < a[j]) {
        if (i > j) c++;
        if (i < j) b++;
      }
    }
    res += min(c, b);
  }
  printf("%d \n", res);
}
int main() {
  GetData();
  Run();
  return 0;
}
