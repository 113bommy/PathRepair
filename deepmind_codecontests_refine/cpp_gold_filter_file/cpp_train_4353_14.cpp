#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,a,b;
  string s;
  cin>>N;
  vector<tuple<string,int,int>> t;
  for(int i=0;i<N;i++){
    cin>>s>>a;
    t.push_back(make_tuple(s,(-1)*a,i+1));
  }
  sort(t.begin(),t.end());
  for(int i=0;i<N;i++){
    tie(s,a,b)=t[i];
    cout<<b<<endl;
  }
}
