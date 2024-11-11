#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  long vreme1 = s * v1 + 2 * t1;
  long vreme2 = s * v2 + 2 * t2;
  if (vreme1 == vreme2) {
    cout << "Friendship" << endl;
  } else if (vreme1 > vreme2) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}
