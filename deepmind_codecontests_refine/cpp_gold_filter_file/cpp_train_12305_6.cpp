#include <bits/stdc++.h>
using namespace std;
long long int nextGood(long long int num) {
  long long int carry = 0, result = 0, multiplier = 1;
  while (num > 0 || carry > 0) {
    long long int rem = (num % 3) + carry;
    carry = 0;
    num = num / 3;
    if (rem >= 2) {
      result = 0;
      rem = 0;
      carry = 1;
    }
    result += rem * multiplier;
    multiplier *= 3;
  }
  return result;
}
int main() {
  long long int q;
  cin >> q;
  while (q--) {
    long long int no;
    cin >> no;
    cout << nextGood(no) << endl;
  }
}
