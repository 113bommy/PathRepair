#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[10];
  cin >> s;
  int q;
  for(int i=0;i<6;i++){
    if(s[i]=='1'){
      q++;
    }
  }
  cout << q;
}
