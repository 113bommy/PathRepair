#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
int arr[mxn], cnt[mxn];
map<int, int> mp, ck;
int MX = 0, tot = 0, id = 0;
int Khela_Hobe() {
  int Ans, p;
  for (int i = 0; i < id; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      p = j;
      Ans = p;
      for (int k = i + 1; k < id; k++) {
        p *= 2;
        if (cnt[k] < p)
          break;
        else
          Ans += p;
      }
      MX = max(MX, Ans);
    }
  }
  return MX;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (ck[mp[arr[i]]] == 0) {
      cnt[id++] = mp[arr[i]];
      ck[mp[arr[i]]] = 1;
    }
  }
  sort(cnt, cnt + id);
  cout << Khela_Hobe() << endl;
  return 0;
}
