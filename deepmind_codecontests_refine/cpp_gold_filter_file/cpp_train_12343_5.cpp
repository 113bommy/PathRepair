#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int cnt0 = 1, cnt1 = 1;
  while (1LL * cnt0 * (cnt0 - 1) / 2 < a) cnt0++;
  while (1LL * cnt1 * (cnt1 - 1) / 2 < d) cnt1++;
  if (1LL * cnt0 * (cnt0 - 1) / 2 > a) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (1LL * cnt1 * (cnt1 - 1) / 2 > d) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (!b && !c && !d) {
    for (int i = 0; i < cnt0; i++) cout << "0";
    return 0;
  }
  if (!a && !b && !c) {
    for (int i = 0; i < cnt1; i++) cout << "1";
    return 0;
  }
  string res = "";
  long long calc = 1LL * cnt0 * cnt1;
  for (int i = 0; i <= cnt1 + 1; i++) {
    if (1LL * i * cnt0 > c) {
      c -= (i - 1) * cnt0;
      calc -= 1LL * (i - 1) * cnt0;
      for (int j = 0; j < i - 1; j++) res += "1";
      break;
    }
  }
  int temp = cnt1 - (int)res.size();
  for (int i = 0; i < cnt0; i++) res += "0";
  if (!c) {
    for (int i = 0; i < temp; i++) res += "1";
  } else if (temp) {
    res += "1", temp--;
    int pos = (int)res.size() - 1;
    while (pos && res[pos - 1] == '0' && c) {
      swap(res[pos - 1], res[pos]);
      c--;
      calc--;
      pos--;
    }
    for (int i = 0; i < temp; i++) res += "1";
  }
  if (!c && calc == b) {
    cout << res << endl;
  } else
    cout << "Impossible" << endl;
  return 0;
}
