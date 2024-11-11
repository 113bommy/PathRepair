#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int>v(4);
  for(int i = 0; i < 6; ++i){
    int x; cin >> x;--x;
    v[x]++;
  }
  sort(v.begin(),b.end());
  if(v[0] == 1 && v[1] == 1 && v[2] == 2 && v[3] == 2)
    cout << "YES" << endl;
  else 
    cout << "NO" << endl;
}