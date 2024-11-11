#include <bits/stdc++.h>
using namespace std;
vector<int> days;
vector<pair<int, int> > blocks;
int n, k, a, b, decomp;
void add(int day, int adding) {
  int old = days[day];
  days[day] += adding;
  if (days[day] > a) days[day] = a;
  int adding_a = days[day] - old;
  int adding_b = max(0, min(b, days[day]) - old);
  int block = day / decomp;
  blocks[block].first += adding_a;
  blocks[block].second += adding_b;
}
int compute(int day) {
  int block = day / decomp;
  int result = 0;
  for (int i = 0; i < block; ++i) result += blocks[i].second;
  for (int i = block * decomp; i < day; ++i) result += min(b, days[i]);
  int next_day = day + k;
  int next_block = next_day / decomp;
  for (int i = next_day; i < min(n, (next_block + 1) * decomp); ++i)
    result += days[i];
  for (int i = next_block + 1; i < decomp; ++i) result += blocks[i].first;
  return result;
}
int main() {
  int q;
  cin >> n >> k >> a >> b >> q;
  days.resize(n, 0);
  decomp = sqrt(n);
  if (decomp * decomp < n) ++decomp;
  blocks.resize(decomp);
  for (int i = 0; i < q; ++i) {
    int numb;
    cin >> numb;
    if (numb == 1) {
      int di, ai;
      cin >> di >> ai;
      add(di - 1, ai);
    } else {
      int pi;
      cin >> pi;
      cout << compute(pi - 1) << endl;
    }
  }
  return 0;
}
