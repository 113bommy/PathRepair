#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long int ctr = 1;
  long long temp_n = n;
  long long digit_count = 0;
  while (temp_n >= 10) {
    temp_n /= 10;
    ctr++;
    digit_count += (ctr - 1) * pow(10, ctr - 2) * 9;
  }
  if (ctr != 1)
    digit_count += (fmod(n, pow(10, ctr - 1)) + 1) * ctr;
  else
    digit_count = n;
  cout << digit_count;
}
