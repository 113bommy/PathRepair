#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  int rupee = 0;
  if (v >= n)
    rupee = n - 1;
  else {
    rupee += v;
    int remain = n - v;
    int sum = ((n - v) * (n - v + 1)) / 2;
    sum--;
    rupee += sum;
  }
  cout << rupee;
}
