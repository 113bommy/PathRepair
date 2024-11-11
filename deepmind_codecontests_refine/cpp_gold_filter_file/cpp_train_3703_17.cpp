#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = (int)(0); i < (int)(n); i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  vector<int> geg(2 * n);
  for (int i = (int)(0); i < (int)(n); i++) {
    geg[a[i]] = b[i];
    geg[b[i]] = a[i];
  }
  vector<int> visited(2 * n);
  vector<int> sol(2 * n);
  for (int i = (int)(0); i < (int)(2 * n); i++) {
    if (visited[i]) {
      continue;
    }
    vector<int> seq;
    seq.push_back(i);
    int v = geg[i];
    visited[i] = 1;
    visited[v] = 1;
    seq.push_back(v);
    v ^= 1;
    while (v != i) {
      visited[v] = 1;
      seq.push_back(v);
      v = geg[v];
      visited[v] = 1;
      seq.push_back(v);
      v ^= 1;
    }
    assert(seq.size() % 2 == 0);
    for (int i = (int)(0); i < (int)(seq.size()); i++) {
      sol[seq[i]] = 1 + i % 2;
    }
  }
  for (int i = (int)(0); i < (int)(n); i++) {
    cout << sol[a[i]] << " " << sol[b[i]] << "\n";
  }
}
