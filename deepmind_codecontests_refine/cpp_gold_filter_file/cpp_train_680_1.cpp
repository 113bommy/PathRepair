#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[505];
int b[505];
int eaterOffset = 0;
vector<char> moveDirs;
vector<int> moves;
map<int, int> offset;
void updateOffsets(int i) {
  for (i = i + 1; i < n; i++) offset[i]--;
}
void killSubsequence(int l, int r) {
  int mval = -1;
  int eaterIdx;
  int direction;
  for (int i = l; i <= r; i++) {
    if (a[i] > mval) {
      mval = a[i];
      eaterIdx = i;
      direction = 0;
    }
    if (a[i] == mval) {
      if ((i < r && a[i + 1] < a[i])) {
        direction = 1;
        eaterIdx = i;
      }
      if ((i > l && a[i - 1] < a[i])) {
        direction = 2;
        eaterIdx = i;
      }
    }
  }
  int offsettedEaterIdx = eaterIdx;
  if (direction == 0 || direction == 2) {
    for (int i = eaterIdx - 1; i >= l; i--) {
      moveDirs.push_back('L');
      moves.push_back(eaterIdx + offset[eaterIdx]);
      offsettedEaterIdx--;
      updateOffsets(i);
    }
    for (int i = eaterIdx + 1; i <= r; i++) {
      moveDirs.push_back('R');
      moves.push_back(eaterIdx + offset[eaterIdx]);
      offsettedEaterIdx--;
      updateOffsets(i);
    }
  } else {
    for (int i = eaterIdx + 1; i <= r; i++) {
      moveDirs.push_back('R');
      moves.push_back(eaterIdx + offset[eaterIdx]);
      updateOffsets(i);
    }
    for (int i = eaterIdx - 1; i >= l; i--) {
      moveDirs.push_back('L');
      moves.push_back(eaterIdx + offset[eaterIdx]);
      offsettedEaterIdx--;
      updateOffsets(i);
    }
  }
}
bool canMake(int ai, int bi) {
  if (ai == n) return bi == k;
  if (bi == k) return ai == n;
  int currentMonster = a[ai];
  int bMonster = b[bi];
  if (currentMonster == bMonster) return canMake(ai + 1, bi + 1);
  bool hasDistinct = false;
  int firstMonster = currentMonster;
  int i;
  for (i = ai + 1; i < n; i++) {
    if (a[i] != firstMonster) hasDistinct = true;
    currentMonster += a[i];
    if (currentMonster >= bMonster) break;
  }
  killSubsequence(ai, i);
  if (currentMonster > bMonster) return false;
  return hasDistinct && canMake(i + 1, bi + 1);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> k;
  for (int i = 0; i < k; i++) cin >> b[i];
  if (canMake(0, 0)) {
    cout << "YES" << endl;
    for (int i = 0; i < moveDirs.size(); i++) {
      cout << moves[i] + 1 << " " << moveDirs[i] << endl;
    }
  } else
    cout << "NO" << endl;
  return 0;
}
