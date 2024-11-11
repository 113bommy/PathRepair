#include <bits/stdc++.h>
using namespace std;
void debugarr(int* arr, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "]" << endl;
}
int main() {
  int n, a, b, c;
  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  int t = a + b + c;
  if (t == 0) {
    printf("%.10lf %.10lf %.10lf\n", double(0), double(0), double(n));
  } else {
    double x = (double)a * n / t;
    double y = (double)b * n / t;
    double z = (double)c * n / t;
    printf("%.10lf %.10lf %.10lf\n", x, y, z);
  }
  return 0;
}
