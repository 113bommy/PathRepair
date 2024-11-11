#include<iostream>
#include<algorithm>
using namespace std;
main(){
  int n;
  while(cin>>n && n){
    int mini=10000,maxi=-10000;
    for(int i=0;i<n;i++){
      int now=0,t;
      for(int j=0;j<5;j++){
	cin>>t;
	now+=t;
      }
      maxi=max(maxi,now);
      mini=min(mini,now);
    }p
    cout << maxi<<" " << mini << endl;
  }
}