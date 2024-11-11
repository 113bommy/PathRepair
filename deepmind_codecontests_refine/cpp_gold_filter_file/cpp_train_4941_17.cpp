#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  int flag = 1;
  long long int k = 1;
  int counter = 0;
  while (flag != 0) {
    if ((n + k) % 3 == 0) {
      if ((n + k) / 3 >= (((k) * (k + 1)) / 2)) {
        flag = 1;
        counter++;
      } else {
        flag = 0;
      }
    }
    ++k;
  }
  cout << counter << endl;
  return 0;
}
