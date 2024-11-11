#include <bits/stdc++.h>
const long long int INF = 1e18L + 5;
using namespace std;
void input() {}
long long int digits(long long int k) {
  long long int digit = 0;
  while (k != 0) {
    k = k / 10;
    digit++;
  }
  return digit;
}
long long int decimalToBinary(long long int N) {
  unsigned long long B_Number = 0;
  int cnt = 0;
  while (N != 0) {
    int rem = N % 2;
    unsigned long long int c = pow(10, cnt);
    B_Number += rem * c;
    N /= 2;
    cnt++;
  }
  return B_Number;
}
long long int a[100001];
void Chefora() {
  for (long long int j = 1; j <= 100001; j++) {
    if (j <= 9) {
      a[j] = j;
    } else {
      a[j] = decimalToBinary(j) / 10;
    }
  }
}
int main() {
  char c;
  cin >> c;
  string s1, s2;
  cin >> s1 >> s2;
  string temp = "6789TJQKA";
  if (s1[1] == s1[1]) {
    if (temp.find(s1[0]) > temp.find(s2[0])) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  } else if (s1[1] == c) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
