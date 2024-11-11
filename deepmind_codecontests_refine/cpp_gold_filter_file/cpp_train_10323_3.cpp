#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int arr[N], fre[11] = {0};
  for (int i = 0; i < N; i++) cin >> arr[i];
  int maq = 0;
  for (int i = 0; i < N; i++) {
    fre[arr[i]]++;
    vector<int> v;
    set<int> s, s2;
    int d;
    for (int j = 1; j < 11; j++)
      if (fre[j]) v.push_back(fre[j]);
    sort(v.begin(), v.end());
    d = v.size();
    int mi = v[0], ma = v[d - 1];
    for (int j = 0; j < d; j++) {
      if (!j && v[j] > 1)
        s.insert(v[0] - 1);
      else if (j)
        s.insert(v[j]);
    }
    if (s.size() <= 1) maq = i + 1;
    for (int j = 0; j < d; j++) {
      if (j == d - 1)
        s2.insert(v[j] - 1);
      else
        s2.insert(v[j]);
    }
    if (s2.size() <= 1) maq = i + 1;
  }
  cout << maq;
}
