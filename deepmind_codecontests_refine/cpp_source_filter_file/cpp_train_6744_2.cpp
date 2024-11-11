#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n,0);
  for(int i=1;i<n;i++){
    int a; cin >> a;  vec.at(a-1)++;
  }
  for(int x : vec) cout >> x >> endl;

    
}