#include <bits/stdc++.h>
using namespace std;
int colsize[100];
int colummns;
bool compare(int x, int y) {
  if (x > y)
    return 0;
  else if (x < y)
    return 1;
}
int main() {
  cin >> colummns;
  for (int i = 0; i < colummns; i++) {
    cin >> colsize[i];
  }
  sort(colsize, colsize + colummns, compare);
  for (int i = 0; i < colummns; i++) {
    cout << colsize[i];
  }
}
