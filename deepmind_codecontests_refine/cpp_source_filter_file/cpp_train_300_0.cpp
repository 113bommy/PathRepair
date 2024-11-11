#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    char a[7],ans[26],b[26],x=0,y=0;
    scanf("%s",a);
    x=strlen(a);
    scanf("%s",ans);
    y=strlen(ans);  

    for(int j=0;j<y;j++)
      b[j]=ans[j];

    for(int k=x-1;k>=0;k--){
      if(a[k]=='C'){//??????
	b[y-1]=ans[0];
	for(int j=1;j<y;j++) b[j-1]=ans[j];
      }
      else if(a[k]=='J'){//??????
	b[0]=ans[y-1];
	for(int j=0;j<y-1;j++) b[j+1]=ans[j];
      }
      else if(a[k]=='E'){//swap
	if(y%2==0)
	  for(int j=0;j<y/2;j++) 
	    swap(b[j],b[j+(y/2)]);
	else
	  for(int j=0;j<y/2;j++) 
	    swap(b[j],b[j+(y/2)+1]);



      }
      else if(a[k]=='A'){//????????????
	int o=y;
	while(1){
	  if(o==0)break;
	  for(int j=0;j<y;j++){
	    b[j]=ans[o-1];
	    o--;
	  }
	}
      }
      else if(a[k]=='M'){//+1
	for(int j=0;j<y;j++) 
	  if(ans[j]>='0'&&ans[j]<='8') b[j]=ans[j]+1;
	  else if(ans[j]=='9') b[j]=ans[j]-9;
      }
      else if(a[k]=='P')//-1
	for(int j=0;j<y;j++) 
	  if(ans[j]>='1'&&ans[j]<='9') b[j]=ans[j]-1;
	  else if(ans[j]=='0') b[j]=ans[j]+9;

      for(int j=0;j<y;j++)
	ans[j]=b[j];
    }h
    for(int j=0;j<y;j++)
      cout<<ans[j];
    cout<<endl;

  }
  return 0;
}