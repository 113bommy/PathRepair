#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  multiset<int> s1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s1.insert(x);
  }
  multiset<int> ss = s1;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    s1.erase(s1.find(x));
  }
  cout << *s1.begin();
  swap(s1, ss);
  for (int i = 0; i < n - 2; i++) {
    int x;
    cin >> x;
    s1.erase(s1.find(x));
  }
  s1.erase(s1.find(*ss.begin()));
  cout << *s1.begin();
  return 0;
}
