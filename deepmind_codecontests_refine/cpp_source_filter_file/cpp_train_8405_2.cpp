#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
struct node {
  int id, num;
  node() {}
  node(int Id, int Num) {
    id = Id;
    num = Num;
  }
};
bool operator<(node a, node b) { return a.num > b.num; }
bool operator>(node a, node b) { return a.num < b.num; }
bool cnt[MAXN];
int N;
string s;
priority_queue<node> q1;
priority_queue<node, vector<node>, greater<node> > q2;
void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    q1.push(node(i + 1, tmp));
    q2.push(node(i + 1, tmp));
  }
  for (int i = 0; i < 2 * N; i++) {
    char op;
    cin >> op;
    if (op == '0') {
      while (!q1.empty()) {
        node f = q1.top();
        int x = f.id;
        if (!cnt[x]) {
          cout << x << ' ';
          cnt[x]++;
          q2.push(f);
          q1.pop();
          break;
        } else {
          q1.pop();
        }
      }
    } else {
      while (!q2.empty()) {
        node f = q2.top();
        int x = f.id;
        if (cnt[x] == 1) {
          cnt[x]++;
          q2.pop();
          cout << x << ' ';
          break;
        } else {
          q2.pop();
        }
      }
    }
  }
}
void Times(int T) {
  while (T--) {
    solve();
  }
}
int main() {
  int T = 1;
  Times(T);
  return 0;
}
