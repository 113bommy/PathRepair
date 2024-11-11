#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int N;
int in[maxn];
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i < 10; i++) cin >> in[i];
  int wi = 1;
  for (int i = 1; i < 10; i++)
    if (in[i] < in[wi]) wi = i;
  int minx = in[wi];
  int first = N / minx;
  if (!first) return puts("-1");
  int r = N % minx;
  for (int i = 1; i <= 10; i++) {
    int v = 0, d = 0;
    for (int j = 1; j < 10; j++)
      if (in[j] - minx <= r) v = j, d = in[j] - minx;
    if (d) {
      for (int j = 0; j < r / d; j++) ans.push_back(v);
      r %= d;
    }
  }
  while (ans.size() < first) ans.push_back(wi);
  for (int v : ans) cout << v;
  cout << endl;
  return 0;
}
