#include<bits/stdc++.h>
using namespace std;
int main(){
  long long h,w,cnt=0;
  char c;
  cin >> h >> w;
  for (int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> c;
      if(c=='#'){
        cnt++;
      }
    }
  }
  if(cnt==h+w-1){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }