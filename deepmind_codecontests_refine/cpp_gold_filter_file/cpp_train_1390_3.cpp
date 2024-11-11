#include <bits/stdc++.h>
using namespace std;
string names[50], compare[50];
int pt[50], wg[50], lg[50];
int n;
bool comp(string a, string b) {
  int ai = find(names, names + n, a) - names;
  int bi = find(names, names + n, b) - names;
  if (pt[ai] != pt[bi])
    return pt[ai] > pt[bi];
  else if (wg[ai] - lg[ai] != wg[bi] - lg[bi])
    return wg[ai] - lg[ai] > wg[bi] - lg[bi];
  else
    return wg[ai] > wg[bi];
}
bool comp2(string a, string b) { return a < b; }
int main() {
  string a, b, inp;
  int sa, sb, ai, bi;
  char ch;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> names[i];
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    cin >> inp >> sa >> ch >> sb;
    a = inp.substr(0, inp.find('-'));
    b = inp.substr(inp.find('-') + 1);
    ai = find(names, names + n, a) - names;
    bi = find(names, names + n, b) - names;
    if (sa > sb)
      pt[ai] += 3;
    else if (sa == sb) {
      pt[ai]++;
      pt[bi]++;
    } else
      pt[bi] += 3;
    wg[ai] += sa;
    lg[ai] += sb;
    wg[bi] += sb;
    lg[bi] += sa;
  }
  for (int i = 0; i < n; i++) compare[i] = names[i];
  sort(compare, compare + n, comp);
  sort(compare, compare + n / 2, comp2);
  for (int i = 0; i < n / 2; i++) cout << compare[i] << endl;
  return 0;
}
