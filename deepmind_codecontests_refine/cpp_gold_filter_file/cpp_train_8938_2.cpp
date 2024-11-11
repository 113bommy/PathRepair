#include<iostream>
using namespace std;
int main(void)
{
  char a[9];
  while(cin>>a)
    {
      int x=0;
      for(int i=0;i<3;i++)
	{
	  
	  
	  if((a[i*3]=='o' && a[i*3+1]=='o' && a[i*3+2]=='o') || (a[i]=='o' && a[i+3]=='o' && a[i+6]=='o'))
	    {
	      cout<<'o'<<endl;
	      x++;
	      break;
	    }
	  else if((a[i*3]=='x' && a[i*3+1]=='x' && a[i*3+2]=='x') || (a[i]=='x' && a[i+3]=='x' && a[i+6]=='x'))
	    {
	      cout<<'x'<<endl;
	      x++;
	      break;
	    }
	  
	}
      if(a[0]=='o' && a[4]=='o' && a[8]=='o' || (a[2]=='o' && a[4]=='o' && a[6]=='o'))
	{
	  cout<<'o'<<endl;
	  x++;
	}
      if((a[0]=='x' && a[4]=='x' && a[8]=='x') || (a[2]=='x' && a[4]=='x' && a[6]=='x'))
	{
	  cout<<'x'<<endl;
	  x++;
	}
 if(x==0)cout<<'d'<<endl;
    }
  return 0;
}