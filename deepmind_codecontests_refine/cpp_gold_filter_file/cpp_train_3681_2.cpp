#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 7;
int x, cnt[MAX_N], fc[MAX_N], l[MAX_N];
char seq[MAX_N];
int main() {
  cin >> seq + 1;
  vector<pair<char, int> > stack;
  int ans = 0, x = 0, y = 0;
  for (int i = 1; seq[i]; i++) fc[i] = fc[i - 1] + (seq[i] == '[');
  for (int i = 1; seq[i]; i++) {
    if (seq[i] == '[' || seq[i] == '(')
      stack.push_back(make_pair(seq[i], i));
    else if (stack.size()) {
      char c = stack.back().first;
      int s = stack.back().second;
      if ((seq[i] == ']' && c != '[') || (seq[i] == ')' && c != '('))
        stack.clear();
      else {
        stack.pop_back(), cnt[i] = cnt[s - 1] + fc[i] - fc[s - 1];
        l[i] = (l[s - 1] == 0) ? s : l[s - 1];
        if (cnt[i] > ans) x = l[i], y = i, ans = cnt[i];
      }
    }
  }
  cout << ans << endl;
  if (ans)
    for (int i = x; i <= y; i++) cout << seq[i];
  else
    cout << "";
  cout << endl;
  return 0;
}
