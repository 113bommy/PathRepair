#include <bits/stdc++.h>
using namespace std;
const int Nmax = 2 * 1e5 + 1;
int n, a, b, k;
char s[Nmax + 4];
queue<pair<int, int> > q;
vector<int> Ans;
int main() {
  cin >> n >> a >> b >> k;
  cin.get();
  cin.getline(s + 1, Nmax);
  int lst = 0, rem = 0;
  s[n + 1] = '1';
  s[n + 2] = '\0';
  for (int i = 1; i <= n + 1; i++)
    if (s[i] == '1') {
      int st = lst + 1;
      int dr = i - 1;
      rem += (dr - st + 1) / b;
      lst = i;
      if (dr - st + 1 >= b) q.push({st, dr});
    }
  while (rem >= a) {
    pair<int, int> cur = q.front();
    q.pop();
    Ans.push_back(cur.first + b - 1);
    if (cur.second - (cur.first + b) + 1 >= b)
      q.push({cur.first + b, cur.second});
    rem--;
  }
  cout << Ans.size() << '\n';
  for (auto it : Ans) cout << it << ' ';
  cout << '\n';
  return 0;
}
