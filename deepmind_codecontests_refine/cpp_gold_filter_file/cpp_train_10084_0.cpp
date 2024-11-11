#include <cstdio>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> PII;

const int M = 100005;

int n, m, q;

int a[M];
bool used[M];
int cnt[M], ord[M];
vector<int> seq;

void add(int x) {
  if (!used[x]) {
    int f = seq.size();
    used[x] = true;
    ord[x] = f;
    if (cnt[f] > 0) {
      cnt[f] -= 1;
      cnt[f + 1] += 1;
    }
    seq.push_back(x);
  } else {
    int k = ord[x];
    if (cnt[k] > 0) {
      cnt[k] -= 1;
      cnt[k + 1] += 1;
    }
  }
}

int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < q; i += 1) {
    cin >> a[i];
    a[i] -= 1;
  }
  reverse(a, a + q);
  cnt[0] = n;
  for (int i = 0; i < q; i += 1) add(a[i]);
  for (int i = 0; i < m; i += 1) if (!used[i]) seq.push_back(i);
  int sh = 0;
  while (!cnt[sh]) sh += 1;
  auto alt = seq;
  sort(alt.begin() + sh, alt.end());
  if (alt == seq) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
