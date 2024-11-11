#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<double>v(n);
  for(auto&e:v)cin >> e;
  double ave=0;
  for(auto&e:v)ave+=e;
  ave = ave / n;
  int argi = 0;
  for(int i = 0; i < n; ++i){
    if(abs(v[i]-ave) < abs(v[argi]-ave))argi = i;
  }
  cout << argi << endl;
}