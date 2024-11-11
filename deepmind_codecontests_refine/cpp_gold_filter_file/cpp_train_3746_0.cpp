#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;
map <string,int> cost;
multimap <string,string>  rule;
set <string> his;
void update(string a){
  multimap<string,string>::iterator it=rule.find(a);
  while(it != rule.end() && it->first == a) {
    if(cost[it->second]>cost[a])cost[it->second]=cost[a], update(it->second);
    it++;
  }
}
int mk_rule(string a){
  if(his.count(a) == 0){
    his.insert(a);    
    multimap<string,string>::iterator it=rule.find(a);
    while(it != rule.end() && it->first == a) cost[a]= min(cost[a],mk_rule(it->second)),it++;
    update(a);
  }
  return cost[a];
}
int main(){
  int n,m,b;
  cin >> n;
  string a,c,ls[5002];
  for(int i=0;i<n;i++) cin >> ls[i] >> b, cost[ls[i]] = b;

  cin >> m;
  for(int i=0;i<m;i++){
    cin >> a >> c;
    rule.insert(pair<string,string>(a,c));
    rule.insert(pair<string,string>(c,a));
  }
  int ans=0;
  for(int i=0;i<n;i++) ans += mk_rule(ls[i]);
  cout << ans <<endl;
  return 0;
}