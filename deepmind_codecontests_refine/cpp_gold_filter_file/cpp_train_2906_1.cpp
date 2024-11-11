#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  int n,p;

  for(;cin>>n>>p,n||p;)
    {
      int count[n];
      memset(count,0,sizeof(count));
      int pp=p;
      for(int i=0;;i++)
	{
	  if(i>=n)
	    i=0;
	  if(pp!=0)
	    {
	      count[i]++;
	      pp--;
	    }
	  else
	    {
	      pp=count[i];
	      count[i]=0;
	    }
	  if(count[i]==p)
	    {
	      cout<<i<<endl;
	      break;
	    }
	}
      
    }
}