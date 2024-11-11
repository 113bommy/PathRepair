#include <bits/stdc++.h>
using namespace std;
void FindSolution(int r) {
  if (r % 2 == 0 || r <= 3) {
    cout << "NO" << endl;
  } else {
    cout << 1 << " " << (r - 3) / 2 << endl;
  }
}
int main() {
  long long r;
  cin >> r;
  FindSolution(r);
}
