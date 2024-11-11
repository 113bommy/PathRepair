#include<bits/stdc++.h>
using namespace std;
string st,st1;
int main()
{
	st1="CODEFESTIVAL2016";
	cin>>st;
	for(int i=0;i<st.size();i++)
	  if(st[i]!=st1[i])z++;
	cout<<z<<endl;
	return 0;
}