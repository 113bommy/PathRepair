#include<iostream>
#include<string>
using namespace std;
int main()
{
	string text,key,temp;
	for(;;)
	{
		text=key="";
		while(getline(cin,text)&&text.empty())
			;
		if(cin.eof())return 0;
		while(getline(cin,temp)&&!temp.empty())
			text+=temp;
		if(cin.eof())return 0;
		while(getline(cin,key)&&key.empty())
			;
		if(cin.eof())return 0;


		int minLen=1e9,minIndex=1e9,minCount=0;
		int i,head,tail;
		int kind=0,curKind;
		bool f[256]={};
		int a[256]={};
		for(i=0;i<key.size();++i)
			if(!f[key[i]]++)
				++kind;
		text+="\0";
		head=tail=curKind=0;
		for(;tail<text.size();)
		{
			for(; head<text.size(); ++head)
			{
				char c=text[head];
				if(f[c]&&!a[c]++)
				{
					if(++curKind==kind)
					{
						++head;
						break;
					}
				}
			}
			for(; tail<text.size(); ++tail)
			{
				char c=text[tail];
				if(f[c]&&!--a[c])
				{
					if(curKind--==kind)
					{
						if(minLen>head-tail)
						{
							minLen=head-tail;
							minIndex=tail;
							minCount=1;
						}
						else if(minLen==head-tail)
							++minCount;
						++tail;
						break;
					}
				}
			}
		}
		cout<<minCount<<endl<<endl;
		if(minLen!=1e9)
		{
			temp = text.substr(minIndex,minLen);
			for(i=0;i<temp.size();++i)
			{
				cout<<temp[i];
				if(i!=temp.size()-1&&i%72==71)cout<<endl;
			}
			cout<<endl<<endl;
		}
	}
}