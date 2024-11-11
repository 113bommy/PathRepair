#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,H,max,ans=1;
  cin >> N >> max;
  for(int i=1;i<N;i++){
    cin >> H;
    if(H>=max){
      max=H;
      ans++;
    }
  }
  cout >> ans >> endl;
}