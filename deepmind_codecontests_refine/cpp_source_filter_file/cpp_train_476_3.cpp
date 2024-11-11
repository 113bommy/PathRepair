#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int a = t1 + s * v1 + t1;
  int b = t2 + s * v2 + t2;
  if (a > b)
    cout << "First" << '\n';
  else if (b > a)
    cout << "Second" << '\n';
  else
    cout << "Friendship" << '\n';
}
