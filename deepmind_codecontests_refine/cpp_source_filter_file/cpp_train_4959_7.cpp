#include <bits/stdc++.h>
using namespace std;
int Gcd(int a, int b) { return (!b) ? a : Gcd(b, a % b); }
int main() {
  int arr[10001], t, gcd = 0;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) scanf("%d", &arr[i]), gcd = Gcd(gcd, arr[i]);
  if (gcd != arr[0])
    printf("-1");
  else {
    printf("%d\n", 2 * t);
    for (int i = 0; i < t; i++) printf("%d %d", arr[0], arr[i]);
  }
}
