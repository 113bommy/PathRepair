#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
using namespace std;
void redirectIO() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
bool have[2100], need[2100];
vector<pair<int, int> > answer;
void rev(int l, int r) {
  answer.push_back(make_pair(l, r));
  int mid = (r - l + 1) / 2;
  for (int i = 0; i < mid; ++i) {
    swap(have[l + i], have[r - i]);
  }
}
int main() {
  redirectIO();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    k--;
    int d = 0;
    for (int i = 0; i < (k); i++) {
      need[d] = true;
      d++;
      need[d] = false;
      d++;
    }
    for (int i = 0; i < ((n - k * 2) / 2); i++) {
      need[d] = true;
      d++;
    }
    for (int i = 0; i < ((n - k * 2) / 2); i++) {
      need[d] = false;
      d++;
    }
    string s;
    cin >> s;
    for (int i = 0; i < (n); i++) {
      have[i] = (s[i] == '(');
    }
    answer.clear();
    for (int i = 0; i < (n); i++) {
      int j = i;
      while (have[j] != need[i]) j++;
      if (j != i) rev(i, j);
    }
    cout << answer.size() << "\n";
    for (pair<int, int> x : answer)
      cout << x.first + 1 << " " << x.second + 1 << "\n";
  }
  return 0;
}
