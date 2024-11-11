#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char s[] = {'a', 'b', 'c', 'd'};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << s[i % 4];
  }
}
