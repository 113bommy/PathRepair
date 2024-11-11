#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> Split(const string &s)
{
	vector<string> v;
	int i=0, j;
	while((j=s.find_first_of(' ',i)) !=string::npos)
	{
		v.push_back(s.substr(i,j-i));
		i=j+1;
	}
	if(i!=s.size()-1)
		v.push_back(s.substr(i));
	return v;
}
int main()
{
	int n;
	string s;
	vector<string>v;
	map<string,int>m;
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(cin>>n,n)
	{
		getline(cin,s);
		m.clear();
		while(n--)
		{
			getline(cin,s);
			v=Split(s);
			for(int i=0;i<v.size();++i)
				++m[v[i]];
		}
		getline(cin,s);
		vector<pair<int,string> >vp;
		for(map<string,int>::iterator ite=m.begin();ite!=m.end();++ite)
		{
			if(ite->first[0]!=s[0])continue;
			vp.push_back(make_pair(-ite->second,ite->first));
		}
		if(vp.empty())cout<<"NA"<<endl;
		else
		{
			sort(vp.begin(),vp.end());
			int end=min(5U,vp.size());
			for(int i=0; i<end; ++i)
				cout<<vp[i].second<<(i+1==end?"\n":" ");
		}
	}
	return 0;
}