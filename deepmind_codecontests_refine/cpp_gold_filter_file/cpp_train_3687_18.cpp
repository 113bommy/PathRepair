#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> vi;
int startHere(int start, int cur) {
  if (cur >= n) return startHere(start, cur - n);
  if (cur == start) return 0;
  return vi[cur] + startHere(start, cur + k);
}
struct node {
  int pos, tot;
};
int getMin(vector<node>& vi) {
  int s = vi.size();
  int poss;
  int mintot = 9999999999;
  for (int i = 0; i < s; i++) {
    if (mintot > vi[i].tot) {
      mintot = vi[i].tot;
      poss = vi[i].pos;
    }
  }
  return poss;
}
int main() {
  cin >> n >> k;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    vi.push_back(temp);
  }
  vector<node> solutions;
  for (int i = 0; i < k; i++) {
    node s;
    s.tot = startHere(i, i + k) + vi[i];
    s.pos = i;
    solutions.push_back(s);
  }
  cout << getMin(solutions) + 1 << endl;
  return 0;
}
