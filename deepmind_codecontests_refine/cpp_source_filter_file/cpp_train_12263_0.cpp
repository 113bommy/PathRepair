#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int i=1;i<50001;i++){
    if(int i*1.08==N){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<":("<<endl;
}

    
    

  
