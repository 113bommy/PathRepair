#include <bits/stdc++.h>
using namespace std;
int seq[128];
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  int sum, can;
  sum = 0;
  can = 1;
  seq[1] = 1;
  int ele = 1;
  if (a && a == n - 1) can = 0;
  if (b) {
    seq[2] = 2;
    ele++;
    b--;
  } else {
    seq[2] = 1;
    ele++;
  }
  for (int e = 1; e <= ele; e++) sum += seq[e];
  while (b) {
    ele++;
    seq[ele] = sum + 1;
    if (seq[ele] > 50000) can = 0;
    sum += seq[ele];
    b--;
  }
  while (a) {
    ele++;
    seq[ele] = seq[ele - 1] + 1;
    if (seq[ele] > 50000) can = 0;
    a--;
  }
  for (int e = ele + 1; e <= n; e++) seq[e] = 1;
  if (can) {
    for (int e = 1; e <= n; e++) cout << seq[e] << " ";
    cout << endl;
  } else {
    cout << "-1" << endl;
  }
  return 0;
}
