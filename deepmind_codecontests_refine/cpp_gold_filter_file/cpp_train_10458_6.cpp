#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  vector<int> vi(6);
  for (int i = 0; i < 6; i++) {
    cin >> vi[i];
  }
  sort(vi.begin(), vi.end());
  int leg = vi[3];
  int c = 0;
  for (int i = 0; i < 6; i++) {
    if (vi[i] == leg) {
      c++;
    }
  }
  if (c < 4) {
    cout << "Alien";
    return 0;
  }
  for (int i = 0; i < 6 and vi.size() > 2; i++) {
    if (vi[i] == leg) {
      vi.erase(vi.begin() + i);
      i--;
    }
  }
  if (vi[0] == vi[1])
    cout << "Elephant";
  else
    cout << "Bear";
}
