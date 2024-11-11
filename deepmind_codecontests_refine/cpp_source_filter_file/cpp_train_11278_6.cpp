#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, sum = 0, a, r, b;
  vector<int> ab;
  cin >> a >> b >> m >> r;
  ab.push_back(r);
  for (i = 0; i < 1000; i++) {
    ab.push_back((a * ab.back() + b) % m);
  }
  for (j = 0; j < ab.size(); j++) {
    for (int z = j + 1; z < ab.size(); z++) {
      if (ab[j] == ab[z]) {
        cout << z - j << endl;
        return 0;
      }
    }
  }
}
