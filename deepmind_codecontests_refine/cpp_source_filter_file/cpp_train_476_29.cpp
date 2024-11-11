#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, s1, s2, t1, t2, t;
  cin >> n >> s1 >> s2 >> t1 >> t2;
  long long a = n * (s1) + 2 * t;
  long long b = n * (s2) + 2 * t;
  if (a < b) {
    cout << "First";
  } else if (b < a) {
    cout << "Second";
  } else {
    cout << "Friendship";
  }
  return 0;
}
