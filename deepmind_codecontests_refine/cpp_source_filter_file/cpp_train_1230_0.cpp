#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[5];
  cin >> s;
  int o=0;
  for(int i=0;i<4;i++){
    if(s[i]=='-')o----;
    o++;
  }
  cout << o;
}