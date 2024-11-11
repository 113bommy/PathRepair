#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >>n;
  set<int> v;
  for(int i=0; i<n; i++){
    int t;
    cin >>t;
    v.insert(t);
  }
  cout << v.size() <<endl;
}
