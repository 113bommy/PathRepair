#include <bits/stdc++.h>
using namespace std;
const int D = 0;
const int M = 1;
const int Y = 2;
int DD, MM, YY;
int BD, BM, BY;
vector<int> V;
bool check() {
  if (V[M] > 12) return false;
  switch (V[M]) {
    case 1:
      if (V[D] > 31) return false;
      break;
    case 2:
      if (V[Y] / 4 == 0) {
        if (V[D] > 29) return false;
      } else {
        if (V[D] > 28) return false;
      }
      break;
    case 3:
      if (V[D] > 31) return false;
      break;
    case 4:
      if (V[D] > 30) return false;
      break;
    case 5:
      if (V[D] > 31) return false;
      break;
    case 6:
      if (V[D] > 30) return false;
      break;
    case 7:
      if (V[D] > 31) return false;
      break;
    case 8:
      if (V[D] > 31) return false;
      break;
    case 9:
      if (V[D] > 30) return false;
      break;
    case 10:
      if (V[D] > 31) return false;
      break;
    case 11:
      if (V[D] > 30) return false;
      break;
    case 12:
      if (V[D] > 31) return false;
      break;
  }
  if (V[Y] < YY) {
    return true;
  }
  if (V[Y] == YY) {
    if (V[M] < MM) {
      return true;
    }
    if (V[M] == MM) {
      if (V[D] <= DD) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d.%d.%d\n", &DD, &MM, &YY);
  YY -= 18;
  if (YY <= 0) {
    cout << "NO";
    return 0;
  }
  scanf("%d.%d.%d", &BD, &BM, &BY);
  V.push_back(BD);
  V.push_back(BM);
  V.push_back(BY);
  sort(V.begin(), V.end());
  do {
    if (check()) {
      cout << "YES";
      return 0;
    }
  } while (next_permutation(V.begin(), V.end()));
  cout << "NO";
  return 0;
}
