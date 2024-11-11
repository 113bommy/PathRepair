#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,d=1;
  cin >> a;
  char s[a+1];
  cin >> s;
  for(i=0;i<a-1;i++){
    if(s[i]!=s[i+1]){
      d++;
    }
  }
  cout << d << endl;
}
