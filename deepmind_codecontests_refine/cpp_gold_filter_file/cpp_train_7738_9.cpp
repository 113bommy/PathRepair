#include <bits/stdc++.h>
using namespace std;
int prime[1000];
int p[1001];
void prme(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (p[i] == 0)
      for (int j = i * i; j <= num; j = j + i) {
        p[j] = 1;
      }
  }
}
int main() {
  int num, k;
  cin >> num >> k;
  for (int i = 1; i <= num; i++) {
    p[i] = 0;
  }
  prme(num);
  int l = 1;
  for (int i = 2; i <= num; i++) {
    if (p[i] == 0) {
      prime[l] = i;
      l++;
    }
  }
  int count = 0;
  for (int i = l - 1; i >= 3; i--) {
    int r = l - 1;
    while (r >= 3) {
      if (prime[i] == prime[r - 1] + prime[r - 2] + 1) {
        count++;
        break;
      }
      r--;
    }
  }
  if (count >= k)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
