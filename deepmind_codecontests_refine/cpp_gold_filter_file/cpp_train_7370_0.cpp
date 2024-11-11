#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
using P = pair<int,int>;
 
signed main(){
  int n;
  cin >> n;
  map<P,int> ans;
  vector<int>a(n),b(n);
  
  for(int i=0 ;i<n ;i++){
    cin >> a[i] >> b[i];
  }
  int ANS = 0;
  for(int i=0; i<n ;i++){
    for(int j=0; j<n; j++){
      if(i != j){
        ans[make_pair(a[i]-a[j],b[i]-b[j])]++;
      }
    }
  }
  for(auto i:ans){
    ANS = max(ANS,i.second);
  }
  cout << n - ANS << endl;
}
        
      
  
    
