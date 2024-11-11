#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[100];
    int k = n;
    arr[0] = k;
    int index = 1;
    for (long long i = 1; i < 100; i++) arr[i] = 0;
    while (index < 100) {
      n++;
      while (n % 10 == 0) {
        n /= 10;
      }
      int flag = 1;
      for (int i = 0; i < 100; i++)
        if (arr[i] == n) flag = 0;
      if (flag == 0)
        break;
      else if (flag == 1) {
        arr[index] = n;
        index++;
      }
    }
    cout << index;
  }
  return 0;
}
