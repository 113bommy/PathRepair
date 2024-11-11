#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
  int ctr = 0;
  	cin>>s;
  
  for(int i=0;i<s.length()/2;i++)
  {
  	if(s[i]!=s[s.length()-i-1]) ctr++;
  }
  
  cout<<ctr<<endl;
}