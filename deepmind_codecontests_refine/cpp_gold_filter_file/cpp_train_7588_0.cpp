#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<bitset>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;
typedef pair<int,int> P;
int n;
int memo[(1<<25)][10];

bool rec(P *G,int used,int prev)
{
  if(__builtin_popcount(used) == n)return true;
  if(__builtin_popcount(used) >= n)return false;
  if(memo[used][prev] != -1)return memo[used][prev];

  rep(i,n)
    {
      if((used>>i)&1)continue;
      if(prev == G[i].first)if(rec(G,used|(1<<i),G[i].second))
			      {
				memo[used|(1<<i)][G[i].second] = true;
				return true;
			      }
      if(prev == G[i].second)if(rec(G,used|(1<<i),G[i].first))
			       {
				 memo[used|(1<<i)][G[i].first] = true;
				 return true;
			       }
    }
  memo[used][prev] = false;
  return false;
}

int main()
{
  while(cin >> n)
    {
      cin.ignore();
      rep(i,(1<<n))rep(j,10)memo[i][j] = -1;
      P G[n];
      rep(i,n)
	{
	  char a,b,c;
	  scanf("%c%c%c",&a,&b,&c);
	  G[i].first = a-'0';
	  G[i].second = b-'0';
	}

      rep(i,n)
	{
	  if(rec(G,(1<<i),G[i].second) || rec(G,(1<<i),G[i].first))
	    {
	      cout << "Yes" << endl;
	      goto F;
	    }
	}
      cout << "No" << endl;
    F:;
    }
  return 0;
}