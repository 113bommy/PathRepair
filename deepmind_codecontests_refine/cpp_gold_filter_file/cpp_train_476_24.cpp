#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, v1, v2, t1, t2;
  cin >> t >> v1 >> v2 >> t1 >> t2;
  int first = v1 * t + t1 * 2;
  int second = v2 * t + t2 * 2;
  if (first < second)
    cout << "First";
  else if (second < first)
    cout << "Second";
  else
    cout << "Friendship";
}
