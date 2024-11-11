#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
const int X = 1e6 + 7;
int used[X];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  char a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i % 4 == 0) a = 'a';
    cout << a;
    a++;
  }
}
