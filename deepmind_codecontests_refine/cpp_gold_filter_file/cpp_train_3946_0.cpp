#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
  while(1){
    int n,k;
    cin>>n>>k;
    if(!n&&!k){break;}
    else{
      int *a;
      a=new int[k];
      for(int i=0;i<k;i++){
	cin>>a[i];
      }
      
      sort(a,a+k);
      int lx=0,l=1;
      
      if(a[0]){
	for(int i=0;i<k-1;i++){
	  if(a[i]+1==a[i+1]){l++;}
	  else{
	    lx=(l>lx)?l:lx;
	    l=1;
	  }
	}

	lx=(l>lx)?l:lx;
      }

      else{
	int m=0;
	for(int i=1;i<k-1;i++){
	  if(a[i]+1==a[i+1]){l++;}
	  else if(a[i]+2==a[i+1]){
	    lx=(lx<l+m)?l+m:lx;
	    m=l+1;l=1;
	  }
	  else{
	    lx=(lx<l+m)?l+m:lx;
	    m=0;l=1;
	  }
	}

	lx=(lx<l+m)?l+m:lx;
      }
      
      cout<<lx<<endl;
      delete []a;
    }
  }
  return 0;
}