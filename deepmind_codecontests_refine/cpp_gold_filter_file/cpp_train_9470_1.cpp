#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <queue>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;
   
  
   
int main(){
   
    int n; 
    int r[1000],w[1000];
    int sum_r=0,sum_w=0,idx=0;
	
    while(scanf("%d",&n),n){
         
        sum_r=sum_w=idx=0;
        for(int i=0;i<n;i++){
            scanf("%d %d",&r[i],&w[i]);
            sum_r+=r[i];
            sum_w+=w[i];
            if(r[idx]<r[i]) idx=i;
        }
  
        int r0=r[idx],r=sum_r-r0;
        w[idx]=0;
 
        if(r0 <= r){
            cout<<sum_r+sum_w<<endl;
        }else{
  
            int res=2*r0;
            //vector<vector<bool> > dp(1001,vector<bool>(1000,false));
  
			bool cur[1001]={};
            cur[0]=true;
            for(int i=0;i<n;i++){
				bool next[1001]={};
                for(int j=0;j<=r0-r;j++){
                    if(cur[j]){
                        next[j]=true; 
                        if(j+w[i]<=r0-r)
                            next[j+w[i]]=true; 
                    }
                }
				swap(cur,next);
            }
  
            int opt=r0-r;
            while(!cur[opt]) opt--;
  
            res+=sum_w-opt;
            printf("%d\n",res);
  
  
  
        }
          
          
    }
}