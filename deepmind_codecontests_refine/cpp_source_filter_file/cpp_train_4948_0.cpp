#include <bits/stdc++.h>
using namespace std;
int n, a[2000001], b[2000001];
vector<int> A, B;
int s = 0, t = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) s = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] == 1) t = 1;
  }
  for (int i = s; i < n; i++)
    if (a[i]) A.push_back(a[i]);
  for (int i = 0; i < s; i++)
    if (a[i]) A.push_back(a[i]);
  for (int i = t; i < n; i++)
    if (b[i]) B.push_back(b[i]);
  for (int i = 0; i < t; i++)
    if (b[i]) B.push_back(b[i]);
  if (A == B) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
