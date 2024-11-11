#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int sum = 0;
  unordered_set<int> s;
  for (int i = 1; i <= 500; i++) {
    sum = sum + i;
    s.insert(sum);
  }
  int n;
  cin >> n;
  if (s.find(n) != s.end())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
