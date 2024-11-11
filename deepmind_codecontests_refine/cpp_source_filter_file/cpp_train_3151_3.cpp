#include <bits/stdc++.h>
using namespace std;
void cout_vector(vector<int> v) {
  for (vector<int>::iterator it = v.begin(); it != prev(v.end()); it++)
    cout << *it << " ";
  cout << *prev(v.end());
  cout << endl;
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
vector<int> liss;
vector<bool> visited;
vector<int> a;
vector<int> b;
void dfs(int i) {
  if (!visited[i]) return;
  if (b[i] != -1) dfs(b[i]);
  liss.push_back(i);
  visited[i] = false;
}
int main() {
  int n;
  long long ans = 0;
  cin >> n;
  vector<int> moves;
  vector<int> last_moves;
  for (int i = 1; i <= n; i++) {
    visited.push_back(true);
  }
  for (int i = 0; i < n; i++) {
    int pp;
    cin >> pp;
    a.push_back(pp);
  }
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num != -1) {
      num--;
      b.push_back(num);
    } else
      b.push_back(-1);
  }
  for (int i = 0; i < n; i++) {
    if (visited[i]) dfs(i);
  }
  while (liss.size() > 0) {
    int num = liss.back();
    liss.pop_back();
    ans += a[num];
    if (a[num] > 0 && b[num] != -1) {
      a[b[num]] += a[num];
      moves.push_back(num + 1);
    } else {
      if (a[num] > 0)
        moves.push_back(num + 1);
      else
        last_moves.push_back(num + 1);
    }
  }
  while (last_moves.size() > 0) {
    moves.push_back(last_moves.back());
    last_moves.pop_back();
  }
  cout << ans << endl;
  cout_vector(moves);
  return 0;
}
