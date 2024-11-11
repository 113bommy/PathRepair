#include<bits/stdc++.h>
using namespace std;
int main(){
long n,m;
cin >> n >> m;
vector<long> l(m);
vector<long> r(m);
  for(long i=0;i<m;i++){
  cin >>l[i]>>r[i];}
sort(l.begin(),l.end());
sort(r.begin(),r.end());
  cout << max(0,r.at(0)-l.at(m-1)) << endl;
}