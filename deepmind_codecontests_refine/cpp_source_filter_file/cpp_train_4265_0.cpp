#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
  string st;
  vector<pair<double,string> >v;
  while(n--){
    int p,a,b,c,d,e,f,s,m;
    cin>>str>>p>>a>>b>>c>>d>>e>>f>>s>>m;
    v.push_back(make_pair(-(double)(s*f*m-p)/(a+b+c+(d+e)*m),str));
  }sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    cout<<v[i].second<<endl;
  }
  cout<<"#"<<endl;
}
}