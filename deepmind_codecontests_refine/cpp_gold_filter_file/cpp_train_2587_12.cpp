#include<bits/stdc++.h>
using namespace std;
int main(){
  long k,s,h=0;
  cin >> k >> s;
  for(int i=0;i<=k;i++){
    for(int j=0;j<=k;j++){
      if(0<=s-i-j&&s-i-j<=k)h++;
    }
  }
  cout << h;
}
