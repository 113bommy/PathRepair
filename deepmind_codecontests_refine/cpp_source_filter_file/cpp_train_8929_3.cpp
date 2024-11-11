#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string,int> m;
  int n;
  cin >> n;
  for(int i=0; i<n;i++){
    string s;
    cin >> s;
    m[s]++;
    }
  int ma=-1;
  for(auto q: m){
    ma = max(ma, q.second);
    }
  for(auto q: m) {
    if(q.second==ma)
      cout << q.first << "\n";
    }
  }
return 0;
  
}