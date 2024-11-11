#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, sum = 0;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; str[i]; i++) {
    if (str[i] % 2 == 0) {
      sum += i + 1;
    }
  }
  cout << sum;
  return 0;
}
