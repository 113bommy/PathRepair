#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
int main() {
  int n, k, j, temp;
  cin >> n >> k;
  int arr[20000];
  vector<pair<int, int> > vec;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    vec.push_back(make_pair(temp, i + 1));
  }
  sort(vec.begin(), vec.end(), cmp);
  temp = k;
  j = 0;
  for (int i = 0; i < (int)vec.size(); i++) {
    temp -= vec[i].first;
    if (temp >= 0)
      arr[j++] = vec[i].second;
    else
      break;
  }
  cout << j << endl;
  for (int i = 0; i < j; i++) cout << arr[i] << " ";
  cout << endl;
  return 0;
}
