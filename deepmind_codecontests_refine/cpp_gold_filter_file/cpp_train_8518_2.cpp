#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize(3)
using namespace std;
string lists[16]={"KIHBR","AKIHBR","KIHABR","KIHBAR","KIHBRA","AKIHABR","AKIHBAR","AKIHBRA","KIHABAR","KIHABRA","KIHBARA","AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA","AKIHABARA"};
string a;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>a;
	for(int i=0;i<16;i++)
		if(a==lists[i])
		{
			cout<<"YES\n";
			return 0;
		}
	cout<<"NO\n";
	return 0;
}

