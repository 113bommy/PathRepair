#include <bits/stdc++.h>
using namespace std;
int n;
float x, ave;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%f%f", &x, &x);
    ave += x;
  }
  ave /= n;
  printf("%f", ave + 5.0);
  return 0;
}
