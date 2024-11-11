#include<iostream> 
#include<string>
using namespace std; 
int main()
{
int s; 
cin>>s;
if(s%111==0)
cout<<s;
else 
{
int k=s/111+1;
cour<<k*111;
}
}