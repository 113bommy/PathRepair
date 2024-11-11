#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int i;
  int a[n];
  int hash[(int)1e5 + 5];
  memset(hash, 0, sizeof(hash));
  for (i = 0; i < n; i++) {
    cin >> a[i];
    hash[a[i]]++;
  }
  int sum2 = 0, sum4 = 0;
  for (i = 1; i <= 1e5; i++) {
    sum2 += hash[i] / 2;
    sum4 += hash[i] / 4;
  }
  int q;
  cin >> q;
  for (i = 0; i < q; i++) {
    string sym;
    cin >> sym;
    int siz;
    cin >> siz;
    sum2 -= hash[siz] / 2;
    sum4 -= hash[siz] / 4;
    if (sym == "+") {
      hash[siz]++;
    } else {
      hash[siz]--;
    }
    sum2 += hash[siz] / 2;
    sum4 += hash[siz] / 4;
    if (sum4 >= 1 && sum2 >= 4)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
