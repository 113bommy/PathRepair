#include <bits/stdc++.h>
using namespace std;
bool checkSubSequence(string subSequence, string superSequence) {
  bool isSubSequence = false;
  int prev = -1;
  int j, k;
  for (j = 0; j < subSequence.size(); j++) {
    for (k = prev + 1; k < superSequence.size(); k++) {
      if (subSequence[j] == superSequence[k]) {
        isSubSequence = true;
        prev = k;
        break;
      }
    }
    if (k >= superSequence.size())
      isSubSequence = false;
    else if (subSequence[j] != superSequence[k])
      isSubSequence = false;
    if (!isSubSequence) break;
  }
  return isSubSequence;
}
int main() {
  string t;
  string p;
  ios_base::sync_with_stdio(false);
  cin >> t;
  cin >> p;
  int a[t.size() + 5];
  bool removed[t.size() + 5];
  memset(removed, false, sizeof(removed));
  int baca;
  for (int i = 0; i < t.size(); i++) {
    cin >> baca;
    a[i] = baca - 1;
  }
  int number_of_move = 0;
  int l = 0;
  int r = t.size();
  int mid;
  bool isSubSequence = true;
  while (l < r) {
    mid = (l + r) / 2;
    string cur = "";
    for (int i = 0; i <= mid; i++) removed[a[i]] = true;
    for (int j = 0; j < t.size(); j++)
      if (!removed[j]) cur += t[j];
    isSubSequence = checkSubSequence(p, cur);
    if (isSubSequence) {
      l = mid;
    } else {
      r = mid;
    }
    if (r - l == 1) break;
    for (int i = 0; i <= mid; i++) removed[a[i]] = false;
  }
  string cur = "";
  for (int i = 0; i < t.size(); i++)
    if (i != a[0]) cur += t[i];
  isSubSequence = checkSubSequence(cur, p);
  if (r == 1 && isSubSequence)
    cout << 1 << endl;
  else if (r == 1 && !isSubSequence)
    cout << 0 << endl;
  else
    cout << r << endl;
  return 0;
}
