#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int s, a, b, x, y;
  cin >> s >> a >> b >> x >> y;
  long long int first = s * a + 2 * x;
  long long int second = s * b + 2 * y;
  if (first > second)
    cout << "First" << endl;
  else if (second > first)
    cout << "Second" << endl;
  else
    cout << "Friendship" << endl;
  return 0;
}
