#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a[4]={0,0,0,0};
  string r[4]={'AC','WA','TLE','RE'};
  cin>>n;
  while(n--){
  string s;
    cin>>s;
    int i=0;
    while(r[i]!=s){
      i++;
    }
    a[i]++; 
  }
  for(int i=0;i<4;i++){
    cout<<r[i]<<" x "<<a[i]<<endl;
  }
  
  return(0);
}


