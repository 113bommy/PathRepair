#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b;
  cin >> a >> b;
  if (a <= 2 && b <= 2) {
    printf("0");
    return 0;
  }
  long long int count = 0;
  while (1) {
    if (a < b) {
      a++;
      b -= 2;
      count++;
      if (a <= 0 || b <= 0) {
        break;
      }
    } else {
      b++;
      a -= 2;
      count++;
      if (a <= 0 || b <= 0) {
        break;
      }
    }
  }
  cout << count << endl;
  return 0;
}
