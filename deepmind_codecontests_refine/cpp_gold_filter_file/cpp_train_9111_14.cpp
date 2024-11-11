#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 2e6 + 5;
int sieve[M], arr[N];
void pre() {
  int h = 2e6 + 2;
  int f = sqrt(h);
  for (int i = 3; i <= f; i++) {
    if (sieve[i]) continue;
    for (int j = i * 3; j <= h; j += i * 2) {
      sieve[j] = 1;
    }
  }
}
bool isPrime(int x) {
  if (x == 2)
    return true;
  else if (x % 2 == 0)
    return false;
  else
    return !sieve[x];
}
int main() {
  pre();
  int n;
  scanf("%d", &n);
  int ones = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
    if (arr[i] == 1) ones++;
  }
  if (ones > 1) {
    for (int i = 1; i <= n; i++) {
      if (arr[i] != 1 && isPrime(arr[i] + 1)) {
        cout << ones + 1 << endl;
        for (int j = 1; j <= ones; j++) {
          cout << 1 << " ";
        }
        cout << arr[i] << endl;
        return 0;
      }
    }
    cout << ones << endl;
    for (int j = 1; j <= ones; j++) {
      cout << 1 << " ";
    }
    cout << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (isPrime(arr[i] + arr[j])) {
        cout << 2 << endl << arr[i] << " " << arr[j] << endl;
        return 0;
      }
    }
  }
  cout << 1 << endl << arr[1] << endl;
  return 0;
}
