#include<bits/stdc++.h>
using namespace std;
int main()
{
  char s[100];
  int count=0;
  cin>>s;
  for(int i=0;i<strlen(s);i++)
  {
if(s[i]!=s[strlen(s)-1-i])
  count++;
  }
  cout<<count/2;
}
    
