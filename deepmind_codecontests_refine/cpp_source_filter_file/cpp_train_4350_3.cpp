#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
void print(ll n)
{ if(n>0)	{
		n--;
		print(n/26);
  cout<<(char)(n%26+97);
		
	} }
int main(){
  ll n; 
  cin>>n; 
  cout<<print(n);
  }
	


