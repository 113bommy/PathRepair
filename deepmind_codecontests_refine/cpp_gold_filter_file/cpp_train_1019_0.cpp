#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long n;
  string s;
  cin >> n >> s;
  long long w=0;
  long long bl;
  long long wr;
  
  for(long i=0; i<n; i++){
    if(s.at(i) == '.'){
      w++;
    }
  }
  
  bl=0;
  wr=w;
  long long res = bl+wr;
  
  for(long i=0; i<n; i++){
    if(s.at(i) == '.'){
      wr--;
    }else{
      bl++;
    }
    
    res = min(res,wr+bl);
  }
  cout << res << endl;
}