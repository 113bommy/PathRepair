#include <bits/stdc++.h>
using namespace std;
int main() {
  int f;
  string a, b, c, d, e, z, g, h;
  cin >> a >> b >> c >> d >> e >> z >> g >> h;
  if (a == "BWBWBWBW" || a == "WBWBWBWB") f++;
  if (b == "BWBWBWBW" || b == "WBWBWBWB") f++;
  if (c == "BWBWBWBW" || c == "WBWBWBWB") f++;
  if (d == "BWBWBWBW" || d == "WBWBWBWB") f++;
  if (e == "BWBWBWBW" || e == "WBWBWBWB") f++;
  if (z == "BWBWBWBW" || z == "WBWBWBWB") f++;
  if (g == "BWBWBWBW" || g == "WBWBWBWB") f++;
  if (h == "BWBWBWBW" || h == "WBWBWBWB") f++;
  if (f == 8)
    cout << "YES";
  else
    cout << "NO";
}
