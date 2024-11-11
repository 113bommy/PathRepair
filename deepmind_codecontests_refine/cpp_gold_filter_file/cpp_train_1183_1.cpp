#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> qu;
  int a;
  for (int i = 0; i <= n - 1; i++) {
    cin >> a;
    qu.push_back(a);
  }
  if (k > n)
    cout << "-1" << endl;
  else {
    int c;
    for (int i = 0; i <= n - 2; i++)
      for (int j = i + 1; j <= n - 1; j++)
        if (qu[j] < qu[i]) {
          c = qu[i];
          qu[i] = qu[j];
          qu[j] = c;
        }
    cout << qu[n - k] << " 0" << endl;
  }
}
