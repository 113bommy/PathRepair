#include <bits/stdc++.h>
using namespace std;
int n;
char t[] = {'a', 'b', 'c', 'd'};
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << t[i % 4];
  }
  return 0;
}
