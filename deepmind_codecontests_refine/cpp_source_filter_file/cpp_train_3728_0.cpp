#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int X,Y,Z,K;
  cin >> X >> Y >> Z >> K;
  
  vector<int> a(X),b(Y),c(Z),v;
  
  for(auto &i:a)cin >> i;
  
  sort(a.begin(), a.end(), greater<int>());
  
  for(auto &i:b)cin >> i;
  
  sort(b.begin(), b.end(), greater<int>());
  
  for(auto &i:c)cin >> i;
  
  sort(c.begin(), c.end(), greater<int>());
  
  for(int i = 0;i<X; i++){
    for(int j = 0;j<Y;j++){
      for(int k = 0;k<Z;k++){
        if((i+1)*(j+1)*(k+1) <= K) v.push_back(a[i]+b[j]+c[k]);
        else break;
      }
    }
  }
  sort(v.begin(), v.end(), greater<int>());
  for(int i = 0;i<k;i++)cout << v[i] << endl;
  
  return 0;
}
  
