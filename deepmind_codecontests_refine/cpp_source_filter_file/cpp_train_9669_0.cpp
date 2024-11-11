#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int i,j,k,l,m,n,x,y,h,w,sum;
  int ans;
 

  
  while(1){
    ans=0;
    sum=0;
    cin >> n;
    if(n == 0)break;

    for(i=0;i<n;i++){
      cin >> x >> y >> h >> w;
      sum = x + y + h;
      if(w<=2){
	if(sum<=60)ans+=600;
	else if(sum<=80)ans+=800;
	else if(sum<=100)ans+=1000;
	else if(sum<=120)ans+=1200;
	else if(sum<=140)ans+=1400;
	else if(sum<=160)ans+=1600;
	else ans+=0;
      }
      else if(w<=5){
        if(sum<=80)ans+=800;
	else if(sum<=100)ans+=1000;
	else if(sum<=120)ans+=1200;
	else if(sum<=140)ans+=1400;
	else if(sum<=160)ans+=1600;
	else ans+=0;
      }
      else if(w<=10){
	 if(sum<=100)ans+=1000;
	else if(sum<=120)ans+=1200;
	else if(sum<=140)ans+=1400;
	else if(sum<=160)ans+=1600;
	else ans+=0;
      }
 else if(w<=15){
	
	 if(sum<=120)ans+=1200;
	else if(sum<=140)ans+=1400;
	else if(sum<=160)ans+=1600;
	else ans+=0;
      }
 else if(w<=20){

	
	 if(sum<=140)ans+=1400;
	else if(sum<=160)ans+=1600;
	else ans+=0;
      }
 else if(w<=25){



	if(sum<=160)ans+=1600;
	else ans+=0;
      }




    }
    cout << ans << endl;



  }