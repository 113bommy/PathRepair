#include <bits/stdc++.h>
using namespace std;
map<int, int> aaa;
int main() {
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a) aaa[a]++;
  }
  cout << aaa.size();
  return 0;
}
