#include <bits/srdc++.h>
using namespace std;
int main(){

  string s;
  int k;
  cin >>s>>k;
  
  int i=0;
  bool a=0;
  while(s[i]==1){
    k--;
  if(k==0){a=1; break;}
    i++;
  }

  
  if(a) cout<< 1<<endl;
else cout<<s[i]<<endl;
}