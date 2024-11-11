#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int num;
  while (n--) {
    scanf("%d", &num);
    printf("%d", num > 2 ? num - 2 : 0);
  }
}
