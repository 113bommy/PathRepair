#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, x;
  cin >> a >> b >> x;
  if (x % 2 == 0) {
    string aa = "", bb = "";
    if (a >= (x / 2 + 1)) {
      for (long long i = 1; i <= x / 2; i++) aa += "10";
      for (long long i = 1; i <= a - (x / 2 + 1); i++) bb += "1";
      for (long long i = 1; i <= b - (x / 2); i++) aa += "0";
      aa += "1";
      bb += aa;
      cout << bb << "\n";
    } else {
      for (long long i = 1; i <= x / 2; i++) aa += "01";
      for (long long i = 1; i <= b - (x / 2 + 1); i++) bb += "0";
      for (long long i = 1; i <= a - (x / 2); i++) aa += "1";
      aa += "0";
      bb += aa;
      cout << bb << "\n";
    }
  } else {
    string aa = "", bb = "";
    for (long long i = 1; i <= (x + 1) / 2; i++) aa += "10";
    for (long long i = 1; i <= b - ((x + 1) / 2); i++) aa += "0";
    for (long long i = 1; i <= a - ((x + 1) / 2); i++) bb += "1";
    bb += aa;
    cout << bb << "\n";
  }
  return 0;
}
