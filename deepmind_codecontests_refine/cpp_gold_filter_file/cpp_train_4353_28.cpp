#include<bits/stdc++.h>
#include<utility>
using namespace std;

int main(){
  int n; cin>>n;
  pair<pair<string,int>,int> rest[110];
  for(int i=0;i<n;i++){
    string s;
    int p;
    cin>>s >>p;
    rest[i]=make_pair(make_pair(s,-p),i);
  }
  sort(rest,rest+n);
  for(int i=0;i<n;i++)cout<<rest[i].second+1<<endl;
}