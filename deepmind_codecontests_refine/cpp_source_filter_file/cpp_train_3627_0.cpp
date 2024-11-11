#include<iostream>
using namespace std;
int main()
{int i,j,k;
cin>>i;
j=i%10;

k=i/10;
if(j==9||k==9)
cout<<Yes;
else
cout<<No;
}