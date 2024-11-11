#include <bits/stdc++.h>
using namespace std;
int main(){
  int R,G,B,N,a=0;
  cin>>R>>G>>B>>N;
  for(int r=0;r<=N/R;i++){
    for(int g=0;g<=(N-R*r)/G;g++){
      if((N-R*r-G*g)%B==0)a++;
    }
  }
  cout<<a<<endl;
}