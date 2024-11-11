#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long int n, k;
  cin >> n >> k;
  long long int c = n / k;
  if (c % 2 == 0) {
    cout << "N0";
  } else
    cout << "YES";
}
int main() {
  fun();
  return 0;
}
