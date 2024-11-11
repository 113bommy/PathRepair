#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<climits>
#include<map>
#include<set>
#include<cassert>
#include<deque>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define INF 1<<27
#define all(n) n.begin(),n.end()
#define insert(a,b,c,d) PP(P(a,b),P(c,d))
#define F first
#define S second
#define FAILED INT_MIN
#define pb push_back
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
using namespace std;
typedef pair<int,int> P;
typedef pair<P,P> PP;

bool check(string s)
{ 
  stack<char> stk;
  stack<int> pos;
  int cnt = 0;
  bool used[s.length()+2];  
  if(s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == ')')return false;
  for(int i=0;i<s.length()+2;i++)used[i] = false;
  
  for(int i=0;i<s.length();i++)
    {
      assert(s[i] != '.');
      if(!(s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '1' || s[i] == '0' || s[i] == ')' || s[i] == '('))return false;
      if(s[i] == '(' || s[i] == ')')
	{
	  if(s[i] == ')' && s[i+1] == '(')return false;
	  if(s[i] == '(' && s[i+1] == ')')return false;
	  if(s[i] == ')' && i+1 < s.length())
	    {
	      if(!(s[i+1] == '+' || s[i+1] == '-' || s[i+1] == '*' || s[i+1] == ')'))return false;
	    }
	  if(s[i] == '(' && i-1 >= 0)
	    {
	      if(s[i-1] == '0' || s[i-1] == '1' || s[i-1] == ')')return false;
	    }
	  
	}
      if(s[i] == '+' || s[i] == '-' || s[i] == '*')
	{
	  if(i == s.length()-1)return false;
	  if(i+1 < s.length() && (s[i+1] == '+' || s[i+1] == '-' || s[i+1] == '*' || s[i+1] == ')'))return false;
	  if(i-1 >= 0 && (s[i-1] == '+' || s[i-1] == '-' || s[i-1] == '*' || s[i-1] == '('))return false;
	}
    }
  
  
  for(int i=0;i < s.length();i++)
    {
      if(s[i] == '(')
	{
	  stk.push(s[i]);
	  pos.push(i);
	}
      else if(s[i] == ')')
	{
	  if((int)stk.size() <= 0)return false;
	  int here = pos.top();
	  bool exist = false;
	  for(int j=here;j<i;j++)
	    {
	      if((s[j] == '+' || s[j] == '-' || s[j] == '*') && !used[j])
		{
		  used[j] = exist = true;
		}
	    }
	  if(!exist)return false;
	  stk.pop();
	  pos.pop();
	}
    }  
  return (int)stk.size() == 0;
}


class Parsing
{
private:
  string parse;
  int pos;
public:
  
  Parsing(string s)
  {
    parse = s;
    pos = 0;
  }
  int fact(){
    if(parse[pos] == '(')
      {
      pos++;
      int p = expression();
      if(!(0<= p && p < 1024))return FAILED;
      if(p == FAILED)return FAILED;
      pos++;
      return p;
      }else
      {
	int p=0,ru = 0;
	string nes;
	nes.clear();
	while('0' == parse[pos] || parse[pos] == '1')
	  {
	    nes += parse[pos];
	    pos++;
	  }
	reverse(all(nes));
	rep(i,nes.length())
	  {
	    if(nes[i] == '1')p += (1<<ru);
	    ru++;
	  }      
	if(!(0<=p && p<1024))return FAILED;
	return p;
      }
  }
  
  int term()
  {
    int p = fact();
    if(p == FAILED)return FAILED;
    while(parse[pos] == '*')
      {
	if(parse[pos] == '*')
	  {
	    pos++;
	    int pre;
	    pre = fact();
	    if(pre == FAILED)return FAILED;
	    p*=pre;
	    if(!(0<=p && p<1024))return FAILED;
	  }
      }
    return p;
  }
  
  int expression()
  {
    int p = term();
    if(!(0<=p && p<1024))return FAILED;
    if(p == FAILED)return FAILED;
    while(parse[pos] == '+' || parse[pos] == '-')
      {
	if(parse[pos] == '+')
	  {
	    pos++;
	    int pre;
	    pre = term();
	    if(!(0<=pre && pre<1024))return FAILED;
	    if(pre == FAILED)return FAILED;
	    p += pre;	    
	    if(!(0<=p && p<1024))return FAILED;
	  }
	else 
	  {
	    pos++;
	    int pre;
	    pre =term();
	    if(!(0<=pre && pre<1024))return FAILED;
	    if(pre == FAILED)return FAILED;
	    p-=pre;
	    if(!(0<=p && p<1024))return FAILED;
	  }
      }
    return p;
  }
};


char key[7] = {'+','*','-','0','1','(',')'};
int Max = -1;
void solve(string s)
{
  rep(i,s.length())
    {
      if(s[i] == '.')
	{
	  rep(j,7){
	    s[i] = key[j];
	    solve(s);
	    s[i] = '.';
	  }
	  break;
	}
      if(i == s.length()-1)
	{
	  //cout << "s = " << s;
	  if(!check(s)){
	    //cout << " is Ver.1 FAILED" << endl;
	    continue;
	  }
	  Parsing par = Parsing(s);
	  int men = par.expression();
	  if(men == FAILED)
	    {
	      //cout << " is Ver.2 FAILED" << endl;
	      continue;
	    }
	  //cout << "is OK" << endl;
	  Max = max(Max,men);
	  if(Max == 1023)return;
	}
    }
}

int main()
{
  string s;
  cin >> s;
  solve(s);
  cout << Max << endl; 
  return 0;
}