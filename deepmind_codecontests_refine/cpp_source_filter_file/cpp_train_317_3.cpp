include <bits/stdc++.h>
using namespace std;

int main(){

  while(1){
  int H, W;
  cin>>H>>W;
  if(H==0&&W==0)break;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if((i+j)%2==0)cout<<"#";
      if((i+j)%2!=0)cout<<".";

    }cout<<endl;
  }cout<<endl;
  }


  return 0;
}

