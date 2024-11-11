#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long num = 0;
  while ((1 + num) * num / 2 <= n) num++;
  num--;
  cout << n - num * (num + 1) / 2 << endl;
  return 0;
}
