#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  const int SIZE = num;
  int bids[SIZE];
  int dummy[SIZE];
  for (int count = 0; count < num; count++) cin >> *(bids + count);
  for (int i = 0; i < num; i++) dummy[i] = bids[i];
  sort(bids, bids + SIZE);
  int p;
  for (p = 0; p < num; ++p) {
    if (bids[SIZE - 1] == dummy[p]) {
      break;
    }
  }
  cout << p + 1 << " " << (bids[SIZE - 2]) << endl;
  return 0;
}
