#include <bits/stdc++.h>
using namespace std;
int main() {
  int number, result;
  cin >> number;
  vector<int> myvector;
  myvector.push_back(2);
  myvector.push_back(7);
  myvector.push_back(2);
  myvector.push_back(3);
  myvector.push_back(4);
  myvector.push_back(4);
  myvector.push_back(3);
  myvector.push_back(5);
  myvector.push_back(1);
  myvector.push_back(2);
  int fr, b;
  b = number % 10;
  number /= 10;
  fr = number;
  result = myvector[fr] * myvector[b];
  cout << result;
  return 0;
}
