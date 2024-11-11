#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<string> A(N);
  vector<string> B(M);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  for(int i=0;i<M;i++){
    cin>>B.at(i);
  }
  for(int y=0;y<=N-M;y++){
    for(int x=0;x<=N-M;x++){
      int count=0;
      for(int by=0;by<=M-1;by++){
          if(B.at(by)==A.at(by+y).substr(x,M)){
            count++;
          }
      }
      if(count==M){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
