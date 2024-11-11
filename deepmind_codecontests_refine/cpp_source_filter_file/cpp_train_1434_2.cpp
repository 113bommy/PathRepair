#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int n , count =0 , flag = 0 ;
  cin>>n;
  while(n--){
     int q, r;
    cin>>q>>r;
    if(q == r) count++;
    else count = 0 ;
  
  
  if(count >= 3){ cout<<"Yes"endl; flag++ ; break;}
   
}
 if(flag == 0) cout<<"No"<endl; 
  
}