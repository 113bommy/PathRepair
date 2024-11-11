#include <bits/stdc++.h>
using namespace std;
void TIME() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int s = 1, counter = 0;
void gcd(int a, int b) {
  for (int i = 0; i < int(100); i++)
    if (a % i == 0 && b % i == 0) {
      s = i;
      break;
    }
  return;
}
void gcd1(int n) {
  for (int i = 2; i < n; i++)
    if (n % i == 0) counter++, n /= i, i = 1;
  return;
}
int arr1[1000], y = 0;
void prime(int n) {
  bool yes = true;
  for (int i = 2; i < n; i++)
    if (n % i == 0 && i != n) {
      yes = false;
      break;
    }
  if (yes) arr1[y] = n, y++;
}
int main() {
  TIME();
  int n, k, sum, counter = 0;
  cin >> n >> k;
  for (int i = 2; i < n; i++) prime(i);
  for (int i = 0; i < int(y - 1); i++) {
    sum = arr1[i] + arr1[i + 1] + 1;
    for (int j = 0; j < int(y); j++)
      if (sum == arr1[j])
        counter++;
      else if (arr1[j] > sum)
        break;
  }
  (counter >= k) ? puts("YES") : puts("NO");
}
