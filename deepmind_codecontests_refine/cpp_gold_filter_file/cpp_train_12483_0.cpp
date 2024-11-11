#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int w,h,d,x,y,vx,vy;
  string s;
  while(cin>>w>>h&&w+h){
    x=y=1;
    vx=0;
    vy=1;
    while(cin>>s&&s!="STOP"){
      if(0){
      }else if(s=="RIGHT"){
	if(vx){
	  if(vx==1){
	    vx=0;
	    vy=-1;
	  }else{
	    vx=0;
	    vy=1;
	  }
	}else{
	  if(vy==1){
	    vx=1;
	    vy=0;
	  }else{
	    vx=-1;
	    vy=0;
	  }
	}
      }else if(s=="LEFT"){
	if(vx){
	  if(vx==1){
	    vx=0;
	    vy=1;
	  }else{
	    vx=0;
	    vy=-1;
	  }
	}else{
	  if(vy==1){
	    vx=-1;
	    vy=0;
	  }else{
	    vx=1;
	    vy=0;
	  }
	}
      }else if(s=="FORWARD"){
	cin>>d;
	x+=vx*d;
	y+=vy*d;
	if(x<1)
	  x=1;
	if(y<1)
	  y=1;
	if(x>w)
	  x=w;
	if(y>h)
	  y=h;
      }else if(s=="BACKWARD"){
	cin>>d;
	x-=vx*d;
	y-=vy*d;
	if(x<1)
	  x=1;
	if(y<1)
	  y=1;
	if(x>w)
	  x=w;
	if(y>h)
	  y=h;
      }
    }
    cout<<x<<" "<<y<<endl;
  }
  return 0;
}