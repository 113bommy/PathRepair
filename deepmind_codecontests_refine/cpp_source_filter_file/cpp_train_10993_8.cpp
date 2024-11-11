#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, t1 = 1, t2 = 1, k = 1, dem = 0;
  string s[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  cin >> n;
  while (1) {
    t2 += pow(2, k) * 5;
    if (n >= t1 && n < t2) {
      t2 = t1;
      while (1) {
        t2 += pow(2, k);
        if (n >= t1 && n < t2) {
          cout << s[dem];
          return 0;
        }
        t1 = t2;
        dem++;
      }
    }
    t1 = t2;
    k++;
  }
  return 0;
}
