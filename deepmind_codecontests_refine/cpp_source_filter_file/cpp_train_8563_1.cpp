#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  scanf("%d", &a);
  int sum = 0;
  int amount = a - 2;
  for (int i = 2; i < a; i++) {
    int el = a;
    while (el != 0) {
      sum += el % i;
      el /= i;
    }
  }
  for (int i = 2; i <= min(sum, amount) / 2; i++) {
    if (sum % i == 0 && amount % i == 0) {
      sum /= i;
      amount /= i;
    }
  }
  printf("%d/%d", sum, amount);
  return 0;
}
