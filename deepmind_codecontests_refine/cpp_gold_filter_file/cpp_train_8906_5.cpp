#include <bits/stdc++.h>
using namespace std;
long long num[100];
int main() {
  num[1] = num[2] = 1;
  for (int i = 3; i < 100; i++) {
    num[i] = num[i - 1] + num[i - 2];
  }
  long long n;
  cin >> n;
  int i;
  for (i = 0; i < 100; i++) {
    if (n < num[i]) break;
  }
  cout << i - 3;
}
