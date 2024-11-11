#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long ll;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i--)

int not_[3]={2,1,0};
int and_[3][3]={{0,0,0},{0,1,1},{0,1,2}};
int or_[3][3]={{0,1,2},{1,1,2},{2,2,2}};

int i,p,q,r;
int rec(string s)
{
  stack<char>key;
  int ans=0,v;
  key.push('+');
  while(i<s.size())
    {
      if(s[i]==')')
	{return ans;}
      else if(s[i]=='+'||s[i]=='-'||s[i]=='*')
	  key.push(s[i++]);
      else
	{
	  if(s[i]=='(')
	    {i++;v=rec(s);}
	  else if(s[i]=='P')v=p;
	  else if(s[i]=='Q')v=q;
	  else if(s[i]=='R')v=r;
	  else
	      v=s[i]-'0';
	  while(!key.empty())
	    {
	      if(key.top()=='+')
		ans=or_[ans][v];
	      else if(key.top()=='-')
		{
		  v=not_[v];
		  if(key.size()==1)ans=v;
		}
	      else if(key.top()=='*')
		ans=and_[ans][v];
	      key.pop();
	    }
	  i++;
	}
    }
  return ans;
}

int main()
{
  string s;
  while(cin>>s)
    {
      if(s[0]=='.')return 0;
      int a,b,c;
      int cnt=0;
      rep(a,3)rep(b,3)rep(c,3)
	{
	  p=a;q=b;r=c;
	  i=0;
	  if(rec(s)==2)cnt++;
	}
      cout<<cnt<<endl;
    }
  return 0;
}