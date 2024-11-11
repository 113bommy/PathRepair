#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int arr[150010], n;
vector<int> fp;
vector<int> temp;
bool check() {
  int i, j;
  for (j = 0; j < (int)temp.size(); j++) {
    i = temp[j];
    if (i == 1 && arr[i] >= arr[i + 1]) return 0;
    if (i == n && n % 2 == 0 && arr[i] <= arr[i - 1]) return 0;
    if (i == n && n % 2 == 1 && arr[i] >= arr[i - 1]) return 0;
    if (i == 1 || i == n) continue;
    if ((i & 1) && i < n && (arr[i] >= arr[i + 1] || arr[i] >= arr[i - 1]))
      return 0;
    else if (!(i & 1) && i > 1 &&
             (arr[i] <= arr[i + 1] || arr[i] <= arr[i - 1]))
      return 0;
  }
  return 1;
}
map<pair<int, int>, bool> ma;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int i, j, test, t = 1;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> arr[i];
  for (i = 1; i <= n; i++) {
    if (i == 1 && i < n && arr[i] >= arr[i + 1]) fp.push_back(i);
    if (i == n && n % 2 == 0 && i > 1 && arr[i] <= arr[i - 1]) fp.push_back(i);
    if (i == n && n % 2 == 1 && i > 1 && arr[i] >= arr[i - 1]) fp.push_back(i);
    if (i == 1 || i == n) continue;
    if ((i & 1) && i < n && (arr[i] >= arr[i + 1] || arr[i] >= arr[i - 1]))
      fp.push_back(i);
    else if (!(i & 1) && i > 1 &&
             (arr[i] <= arr[i + 1] || arr[i] <= arr[i - 1]))
      fp.push_back(i);
  }
  int ans = 0;
  if ((int)fp.size() > 10) {
    deb(ans);
    return 0;
  }
  for (i = 1; i <= n; i++)
    for (j = 0; j < (int)fp.size(); j++) {
      temp = fp;
      if (i == fp[j]) continue;
      pair<int, int> temp2 = make_pair(i, fp[j]);
      if (temp2.first > temp2.second) swap(temp2.first, temp2.second);
      if (ma.find(temp2) != ma.end()) continue;
      ma[temp2] = 1;
      swap(arr[i], arr[fp[j]]);
      temp.push_back(i);
      if (i < n) temp.push_back(i + 1);
      if (i > 1) temp.push_back(i - 1);
      if (check()) ans++;
      swap(arr[i], arr[fp[j]]);
    }
  deb(ans);
  return 0;
}
