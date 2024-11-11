#include <bits/stdc++.h>
using namespace std;

int main(){
  stack<int> S1;
  stack<pair<int,int> > S2;
  char ch;
  int sum = 0;
  int i,j,a;
  for( i = 0; cin >> ch ; i++){
    if(ch == '\\'){
      S1.push(i);
    }
    else if( ch == '/' && S1.size() > 0){
      j = S1.top();
      S1.pop();
      sum += i - j;
      a = i - j;
      while(S2.size() > 0 && S2.top().first > j){
        a += S2.top().second;
        S2.pop();
      }
      S2.push( make_pair(j,a) );
    }
  }

  vector<int> ans;
  int t = 0;
  while(S2.size() > 0){
    ans.push_back( S2.top().second );
    S2.pop();
  }
  reverse( ans.begin(), ans.end() );
  cout << sum << endl;
  cout << ans.size();
  for( i = 0; i < ans.size(); i++){
    cout << " ";
    t += ans[i];
    cout << ans[i];
  }
  cout << endl;
  return 0;