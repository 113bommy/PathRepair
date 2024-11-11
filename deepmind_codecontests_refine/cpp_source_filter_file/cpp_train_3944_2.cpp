#include <bits/stdc++.h>
using namespace std;

using namespace std;

typedef pair<int,string> P;

int main(){
  int d[4] = {-1,1,-4,4};
  map<string,int> ans;
  ans["01234567"] = 0;
  queue<P> que;
  que.push(P(0,"01234567"));

  while(que.size()){
    P p = que.front(); que.pop();
    int k = ans[p.second];
    for(int i = 0;i < 4;i++){
      int n = p.first + d[i];
      if(i == 0 && n == 3)continue;
      if(i == 1 && n == 4)continue;
      if(n >= 0 && n < 8){
	       string tmp;
	       tmp = p.second
	       tmp[p.first] = tmp[n];
         tmp[n] = '0';
         if(ans.find(tmp) == ans.end()){
	          ans[tmp] = k + 1;
	          que.push(P(n,tmp));
	        }
        }
      }
    }
  string s;
  char t;
  while(cin >> t){
    s += t;
    for(int i = 0;i < 7;i++){
      cin >> t;
      s += t;
    }
    cout << ans[s] << endl;
    s.clear();
  }

  return 0;

}