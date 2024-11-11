#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
vector<pair<string, int>> afis;
priority_queue<int, vector<int>, greater<int>> pq;
int H[maxn];
int n;
void up(int poz) {
  if (poz / 2 == 0) return;
  if (H[poz] < H[poz / 2]) {
    swap(H[poz], H[poz / 2]);
    up(poz / 2);
  }
  return;
}
void push(int x) {
  H[++n] = x;
  up(n);
}
void down(int F) {
  int S = F * 2;
  if (S > n) return;
  if (S < n && H[S] > H[S + 1]) S++;
  if (S <= n && H[F] > H[S]) {
    swap(H[F], H[S]);
    down(S);
  }
  return;
}
void pop() {
  swap(H[1], H[n]);
  n--;
  down(1);
}
inline bool emptyh() {
  if (n == 0) return 1;
  return 0;
}
int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    string op;
    int nr;
    cin >> op;
    if (op == "insert") {
      cin >> nr;
      push(nr);
      afis.push_back(make_pair("insert", nr));
    } else if (op == "removeMin") {
      if (emptyh()) afis.push_back(make_pair("insert", 0));
      afis.push_back(make_pair("removeMin", 0));
      if (!emptyh()) pop();
    } else {
      cin >> nr;
      while (!emptyh() && H[1] < nr) {
        afis.push_back(make_pair("removeMin", 0));
        pop();
      }
      if (emptyh() || H[1] > nr) {
        afis.push_back(make_pair("insert", nr));
        push(nr);
      }
      afis.push_back(make_pair("getMin", nr));
    }
  }
  cout << afis.size() << "\n";
  for (auto it : afis) {
    if (it.first == "removeMin")
      cout << it.first << "\n";
    else
      cout << it.first << " " << it.second << "\n";
  }
  return 0;
}
