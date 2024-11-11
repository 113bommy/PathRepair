#include <bits/stdc++.h>
using namespace std;
bool helper(int n);
int main() {
  int n;
  cin >> n;
  while (helper(++n))
    ;
  cout << n;
  return 0;
}
bool helper(int n) {
  unordered_set<int> s;
  while (n != 0) {
    int pop = n % 10;
    if (s.count(pop) != 0) return true;
    n /= 10;
    s.insert(pop);
  }
  return false;
}
