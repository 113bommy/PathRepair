#include <bits/stdc++.h>
using namespace std;
long long int a[100005];
long long int used[100005];
vector<vector<long long int> > vec[5];
vector<vector<long long int> > ans;
vector<vector<long long int> > rev;
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < ((long long int)(n)); i++) cin >> a[i];
  for (long long int i = 0; i < ((long long int)(n)); i++) a[i]--;
  memset(used, 0, sizeof(used));
  for (long long int i = 0; i < ((long long int)(n)); i++)
    if (!used[i]) {
      vector<long long int> v;
      long long int pos = i;
      do {
        v.push_back(pos);
        used[pos] = true;
        pos = a[pos];
      } while (pos != i);
      while (4 <= ((long long int)v.size())) {
        vector<long long int> V;
        while (((long long int)v.size()) && ((long long int)V.size()) < 5) {
          V.push_back(v.back());
          v.pop_back();
        }
        ans.push_back(V);
        for (long long int i = 0;
             i < ((long long int)(((long long int)V.size()) - 1)); i++)
          swap(V[i], V[i + 1]);
        rev.push_back(V);
        v.push_back(ans.back().back());
      }
      if (((long long int)v.size()) == 2 || ((long long int)v.size()) == 3)
        vec[((long long int)v.size())].push_back(v);
    }
  while (((long long int)vec[2].size()) < ((long long int)vec[3].size())) {
    vector<long long int> v, rv;
    for (long long int i = 0; i < ((long long int)(3)); i++)
      v.push_back(vec[3].back()[i]);
    for (long long int i = 0; i < ((long long int)(3)); i++)
      rv.push_back(vec[3].back()[(i + 1) % 3]);
    vec[3].pop_back();
    if (((long long int)vec[3].size())) {
      v.push_back(vec[3].back()[2]);
      v.push_back(vec[3].back()[1]);
      rv.push_back(vec[3].back()[1]);
      rv.push_back(vec[3].back()[2]);
      vec[3].back().pop_back();
      vec[3].back().pop_back();
      vec[3].back().push_back(v.back());
      vec[2].push_back(vec[3].back());
      vec[3].pop_back();
    }
    ans.push_back(rv);
    rev.push_back(v);
  }
  while (((long long int)vec[3].size())) {
    vector<long long int> v, rv;
    for (long long int i = 0; i < ((long long int)(3)); i++)
      v.push_back(vec[3].back()[(i + 1) % 3]);
    for (long long int i = 0; i < ((long long int)(3)); i++)
      rv.push_back(vec[3].back()[i]);
    for (long long int i = 0; i < ((long long int)(2)); i++)
      v.push_back(vec[2].back()[i]);
    for (long long int i = 0; i < ((long long int)(2)); i++)
      rv.push_back(vec[2].back()[(i + 1) % 2]);
    vec[3].pop_back();
    vec[2].pop_back();
    ans.push_back(v);
    rev.push_back(rv);
  }
  while (((long long int)vec[2].size())) {
    vector<long long int> v, rv;
    for (long long int i = 0; i < ((long long int)(2)); i++)
      v.push_back(vec[2].back()[i]);
    for (long long int i = 0; i < ((long long int)(2)); i++)
      rv.push_back(vec[2].back()[1 - i]);
    vec[2].pop_back();
    if (((long long int)vec[2].size())) {
      for (long long int i = 0; i < ((long long int)(2)); i++)
        v.push_back(vec[2].back()[i]);
      for (long long int i = 0; i < ((long long int)(2)); i++)
        rv.push_back(vec[2].back()[1 - i]);
      vec[2].pop_back();
    }
    ans.push_back(v);
    rev.push_back(rv);
  }
  cout << ((long long int)ans.size()) << endl;
  for (long long int i = 0; i < ((long long int)(((long long int)ans.size())));
       i++) {
    cout << ((long long int)ans[i].size()) << endl;
    for (long long int j = 0;
         j < ((long long int)(((long long int)ans[i].size()))); j++)
      cout << rev[i][j] + 1 << " ";
    cout << endl;
    for (long long int j = 0;
         j < ((long long int)(((long long int)rev[i].size()))); j++)
      cout << ans[i][j] + 1 << " ";
    cout << endl;
  }
}
