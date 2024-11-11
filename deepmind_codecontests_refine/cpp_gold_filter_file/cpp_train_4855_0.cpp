#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, count_beauty = 1, beauty, k = 1;
  cin >> num;
  while (num >= count_beauty) {
    if (num % count_beauty == 0) {
      beauty = count_beauty;
    }
    count_beauty = (pow(2, k) - 1) * pow(2, k - 1);
    k++;
  }
  cout << beauty;
  return 0;
}
