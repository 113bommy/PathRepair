#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int req{0};
  req += n / 100;
  n %= 100;
  req += n / 20;
  n %= 20;
  req += n / 10;
  n %= 10;
  req += n / 5;
  n %= 5;
  req += n;
  cout << req << endl;
}
