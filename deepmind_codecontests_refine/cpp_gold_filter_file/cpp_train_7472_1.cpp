#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;



int main(){
  int n;
  cin >> n;
  string s[n];
  vector<pair<int,int>> ls,rs;
  int sum=0;
  rep(i,n){
    cin >> s[i];
    int tmp=0,min=0;
    rep(j,(int)s[i].size()){
      if(s[i][j]=='('){
        tmp++;
        sum++;
      }else{
        tmp--;
        if(tmp<min)min=tmp;
        sum--;
      }
    }
    if(tmp>0)ls.emplace_back(min,tmp);
    else rs.emplace_back(min-tmp,-tmp);
  }
  if(sum!=0){
    cout << "No\n";
    return 0;
  }
  sort(ls.rbegin(), ls.rend());
  sort(rs.rbegin(), rs.rend()); 
  int h=0;
  for(auto l: ls){
    if(h+l.first<0){
      cout << "No\n";
      return 0;
    }
    h += l.second;
  }
  int h2=0;
  for(auto r: rs){
    if(h2+r.first<0){
      cout << "No\n";
      return 0;
    }
    h2 += r.second;
  }
  cout << "Yes\n";

  return 0;
}