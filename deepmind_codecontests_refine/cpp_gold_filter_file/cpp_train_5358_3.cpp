#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int binaryToDecimal(int n) {
  int num = n;
  int dec_value = 0;
  int base = 1;
  int temp = num;
  while (temp) {
    int last_digit = temp % 10;
    temp = temp / 10;
    dec_value += last_digit * base;
    base = base * 2;
  }
  return dec_value;
}
int main() {
  c_p_c();
  int a, b;
  cin >> a;
  cin >> b;
  if (a >= b) {
    vector<int> c;
    c.push_back(1);
    int d = 2;
    d += b;
    while (d <= a + b + 1) {
      c.push_back(d);
      d += 1;
    }
    d = 1 + b;
    int e = 0;
    while (e < b) {
      c.push_back(d);
      e += 1;
      d -= 1;
    }
    for (long long i = 0; i < a + b + 1; i++) {
      cout << c[i] << " ";
    }
  } else {
    vector<int> c;
    c.push_back(a + b + 1);
    int d = a + b;
    d -= a;
    while (d >= 1) {
      c.push_back(d);
      d -= 1;
    }
    d = b + 1;
    int e = 0;
    while (e < b) {
      c.push_back(d);
      e += 1;
      d += 1;
    }
    for (long long i = 0; i < a + b + 1; i++) {
      cout << c[i] << " ";
    }
  }
}
