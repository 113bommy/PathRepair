#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int id = 30; id <= 50; id++) {
    cout << (((min(id, 25) + id) % (2 + id % 3)) > 0);
    cout << endl;
  }
}
