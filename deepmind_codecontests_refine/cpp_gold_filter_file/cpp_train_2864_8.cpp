#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q;
  cin >> n >> q;
  long long a[(int)1e5] = {}, b[(int)1e5] = {};
  for (int x = 0; x < n; x++) cin >> a[x];
  for (int x = 0; x < n - 1; x++) b[x] = abs(a[x] - a[x + 1]);
  for (int x = 0; x < q; x++) {
    long long a1, b1;
    cin >> a1 >> b1;
    a1--;
    b1 -= 2;
    if (a1 == b1) {
      cout << b[a1] << endl;
      continue;
    }
    int maxPosR[(int)1e5] = {};
    maxPosR[b1] = b1;
    stack<pair<int, int> > s1;
    s1.push({b[b1], b1});
    for (int y = b1 - 1; y >= a1; y--) {
      while (!s1.empty() && s1.top().first <= b[y]) s1.pop();
      if (s1.empty())
        maxPosR[y] = y;
      else
        maxPosR[y] = s1.top().second;
      s1.push({b[y], y});
    }
    int maxPosL[(int)1e5] = {};
    maxPosL[a1] = a1;
    stack<pair<int, int> > s2;
    s2.push({b[a1], a1});
    for (int y = a1 + 1; y <= b1; y++) {
      while (!s2.empty() && s2.top().first < b[y]) s2.pop();
      if (s2.empty())
        maxPosL[y] = y;
      else
        maxPosL[y] = s2.top().second;
      s2.push({b[y], y});
    }
    long long result = 0;
    for (int y = a1; y <= b1; y++) {
      long long length1 = 0, length2 = 0;
      if (maxPosL[y] == y)
        length1 += y - a1 + 1;
      else
        length1 += y - maxPosL[y];
      if (maxPosR[y] == y)
        length2 += b1 - y + 1;
      else
        length2 += maxPosR[y] - y;
      result += length2 * length1 * b[y];
    }
    cout << result << endl;
  }
}
