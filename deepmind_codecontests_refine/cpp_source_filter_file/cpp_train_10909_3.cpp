#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string s;
  cin >> s;
  int cnt=0;
  for(int i=0,i<1000;i++){
    int c[3] = {i/100,(i%100)/10,i%10};
    int f=0;
    for(int j=0;j<N;j++){
      if(s[j]==c[f]){
        f++;
      }
      if(f==3){
        break;
      }
    }
    if(f==3){
      cnt++;
    }
  }
  cout << cnt << endl;
}