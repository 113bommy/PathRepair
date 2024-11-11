#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
  	cin>>n;
	m=n/100;
	if(((m*100)+(m*10)+m)<n)
		m++;
	cout<<m<<m<<m;
}