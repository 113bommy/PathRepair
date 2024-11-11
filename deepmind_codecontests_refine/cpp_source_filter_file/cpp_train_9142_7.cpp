#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int m;
  set<int> d;
  for(int i=0; i<n; i++){
    cin >> m;
    d.push(m);
  }
  cout << d.size() << endl;
  return 0;
}
