#include<bits/stdc++.h>
using namespace std;
int a,b,c;
multiset<string>s;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i = 1;i<=a;i++)s.insert("a");
	for(int i = 1;i<=b;i++)s.insert("b");
	for(int i = 1;i<=c;i++)s.insert("c");
	for(int i = 1;i<r+b+g;i++)
	{
		string x = *s.begin(),y = *(--s.end());
		s.erase(s.lower_bound(x)),s.erase(s.lower_bound(y));
		s.insert(x+y);
	}cout<<*s.begin();
	return 0;
}