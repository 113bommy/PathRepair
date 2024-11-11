#include <bits/stdc++.h>
using namespace std;
int main() {
  float x, y, r;
  scanf("%f%f%f", &x, &y, &r);
  if (r * 2 <= x && r * 2 <= y) {
    printf("First");
  } else {
    printf("Second");
  }
  return 0;
}
