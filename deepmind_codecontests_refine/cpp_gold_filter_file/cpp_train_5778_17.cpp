#include <bits/stdc++.h>
using namespace std;
int Area(int n) { return n * n; }
int main() {
  vector<int> s;
  int i, M = 0;
  for (i = 0; i < 6; i++) {
    int t;
    cin >> t;
    M = max(M, t);
    s.push_back(t);
  }
  int base, left, right, Front;
  for (i = 0; i < 6; i++) {
    if (s[i] == M && i == 0) {
      right = 1;
      left = 5;
      Front = 3;
      base = s[1] + s[5] + s[0];
      break;
    }
    if (s[i] == M && i == 5) {
      right = 4;
      left = 0;
      Front = 2;
      base = s[0] + s[5] + s[4];
      break;
    }
    if (s[i] == M) {
      right = i + 1;
      left = i - 1;
      Front = (i + 3) % 6;
      base = s[i + 1] + s[i - 1] + s[i];
      break;
    }
  }
  cout << Area(base) - Area(s[left]) - Area(s[right]) - Area(s[Front]);
  return 0;
}
