#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, pair<int, int> > mp;
  map<int, pair<int, int> >::iterator it;
  pair<int, int> pa;
  int n;
  scanf("%d", &n);
  int c[n];
  int p[n][n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    sum += c[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c[i]; j++) {
      scanf("%d", &p[i][j]);
      pa = make_pair(i, j);
      mp[p[i][j]] = pa;
    }
  }
  int k = 1;
  int count = 0;
  vector<int> a1, a2, a3, a4;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c[i]; j++) {
      pa = mp.find(k)->second;
      if (!(i == pa.first && j == pa.second)) {
        a1.push_back(i + 1);
        a2.push_back(j + 1);
        a3.push_back(pa.first + 1);
        a4.push_back(pa.second + 1);
        int temp = p[i][j];
        p[i][j] = p[pa.first][pa.second];
        p[pa.first][pa.second] = temp;
        mp[k] = make_pair(i, j);
        mp[p[pa.first][pa.second]] = pa;
        count++;
      }
      k++;
    }
  }
  cout << count << endl;
  for (int i = 0; i < a1.size(); i++) {
    cout << a1[i] << " " << a2[i] << " " << a3[i] << " " << a4[i] << endl;
  }
  return 0;
}
