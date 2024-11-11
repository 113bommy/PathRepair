#include <bits/stdc++.h>
using namespace std;
bool possible(const string& s, int start, int pivot, int k) {
  if (2 * pivot - start > s.size() + k) return false;
  for (int i = start; i < pivot && i - start + pivot < s.size(); ++i) {
    if (s[i] != s[pivot + i - start]) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  int k;
  cin >> s >> k;
  int best = 0;
  for (int pivot = 0; pivot <= (s.size() + k) / 2; ++pivot) {
    for (int start = 0; start < pivot; ++start) {
      if (possible(s, start, pivot, k)) {
        best = max(best, 2 * (pivot - start));
      }
    }
  }
  cout << best;
  return 0;
}
