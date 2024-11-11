#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[20];
  cin >> s;
  int n=strlen(s),a,b=0;
  for(int i=0;i<n;i++){
    a=0;
    for(int j=i;j<n;j++){
      if(s[j]=='A'||s[j]=='G'||s[j]=='C'||s[j]=='T')a++;
      else break;
    }
    if(b<a)b=a;
  }
  cout << b;
}
