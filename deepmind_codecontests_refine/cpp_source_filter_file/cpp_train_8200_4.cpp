#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> a;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a[tmp] = 1;
  }
  if (a.size() == n)
    cout << "Yes";
  else
    cout << "No";
}
