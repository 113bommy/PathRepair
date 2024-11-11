#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 5;
bool sito[N];
int zlicz[4];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, pt, a;
  cin >> n;
  sito[0] = sito[1] = 1;
  for (int i = 2; i * i <= n * 2; i++) {
    if (sito[i]) continue;
    for (int j = i * i; j <= n * 2; j += i) sito[j] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a;
    zlicz[a]++;
  }
  pt = 0;
  while (zlicz[1] && zlicz[2]) {
    if (!sito[pt + 1]) {
      cout << 1 << ' ';
      zlicz[1]--;
      pt++;
    } else {
      cout << 2 << ' ';
      zlicz[2]--;
      pt += 2;
    }
  }
  for (int i = 1; i <= zlicz[1]; i++) cout << 1 << ' ';
  for (int i = 1; i <= zlicz[2]; i++) cout << 2 << ' ';
  cout << '\n';
  return 0;
}
