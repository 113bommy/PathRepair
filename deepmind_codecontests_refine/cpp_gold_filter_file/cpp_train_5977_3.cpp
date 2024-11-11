#include <bits/stdc++.h>
using namespace std;
void func() {
  int a;
  for (int i = 0; i < 4000; i++) a = i;
}
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  int arr[t];
  func();
  int aa[4000];
  for (int i = 0; i < t; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + t);
  int g = gcd(arr[0], arr[1]);
  for (int i = 2; i < t; i++) g = gcd(g, arr[i]);
  int m = (arr[t - 1] / g - t);
  if (m % 2 == 0)
    cout << "Bob";
  else
    cout << "Alice";
}
