#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int i,n;
  char s[101];
  cin >> s;
  for(i=0;;i++){
    if(s[i]!='1'){
      break;
    }
  }
  cin >> n;
  if(i>=n){
    cout << 1;
  }else{
    cout << s[i];
  }
}
