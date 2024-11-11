//itp1_topic6_c
#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin>>n;

  int num[4][3][10] = {};
  for(int i=0;i<n;i++){
    int b, f, r, v;
    cin>>b>>f>>r>>v;
    num[b-1][f-1][r-1] += v;
  }  

  for(int i=0;i<4;i++){
    if(i) cout<<"####################"<<endl;

    for(int j=0;j<3;j++){
      for(int k=0;k<10;k++){
        cout<<" "<<num[i][j][k];
      }
      cout<<endl;
    }
  }
  
  return 0;
}

