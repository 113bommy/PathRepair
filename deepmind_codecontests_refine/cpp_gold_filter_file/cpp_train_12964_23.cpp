#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long n;
vector<int> t(150000, 0);
vector<int> correct(150000, 0);
vector<int> a;
long long nCorrect = 0;
bool valid(int i) {
  if (i < 0 || i >= n - 1) return 1;
  if (i % 2 == 0)
    return (t[i] < t[i + 1] && (i == 0 || t[i] < t[i - 1]));
  else
    return (t[i] > t[i + 1] && (i == 0 || t[i] > t[i - 1]));
}
void reCalc(int i) {
  if (i < 0 || i > n - 1) return;
  nCorrect -= correct[i];
  correct[i] = valid(i);
  nCorrect += correct[i];
  return;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (int)(0); i < ((int)n); i++) {
    cin >> t[i];
  }
  for (int i = (int)(0); i < ((int)n); i++) {
    correct[i] = valid(i);
    nCorrect += correct[i];
    if (!correct[i]) a.push_back(i);
  }
  if (a[a.size() - 1] != n - 1) a.push_back(n - 1);
  if (a[0] != 0) a.push_back(0);
  set<pair<int, int> > ans;
  if (a.size() > 10) {
    cout << "0" << endl;
    return 0;
  }
  for (int i = (int)(0); i < ((int)a.size()); i++) {
    for (int j = (int)(0); j < ((int)n); j++) {
      swap(t[a[i]], t[j]);
      reCalc(a[i] - 1);
      reCalc(a[i]);
      reCalc(a[i] + 1);
      reCalc(j - 1);
      reCalc(j);
      reCalc(j + 1);
      if (nCorrect == n) ans.insert(make_pair(min(a[i], j), max(a[i], j)));
      swap(t[a[i]], t[j]);
      reCalc(a[i] - 1);
      reCalc(a[i]);
      reCalc(a[i] + 1);
      reCalc(j - 1);
      reCalc(j);
      reCalc(j + 1);
    }
  }
  cout << ans.size() << endl;
  return 0;
}
