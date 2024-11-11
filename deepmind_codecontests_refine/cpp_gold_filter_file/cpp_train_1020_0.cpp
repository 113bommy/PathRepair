#include <bits/stdc++.h>
using namespace std;

long long N;

void rec(long long d, int use, long long &cnt) {
  if (d > N) return;
  if (use == 0b111) cnt++;

  rec(d * 10 + 7, use | 0b001, cnt);
  rec(d * 10 + 5, use | 0b010, cnt);
  rec(d * 10 + 3, use | 0b100, cnt);
}

int main() {
  cin >> N;
  long long res = 0;
  rec(0, 0, res); 
  cout << res << endl;
}