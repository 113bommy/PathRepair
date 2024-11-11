#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,m;
  while(1){
    cin >> n >> m;
    if(n==0) return 0;
    vector<int> ma(n,0),mi(n,0);
    int s,k;
    int c;
    for(int i=0;i<m;i++){
      cin >> s >> k;
      if(k==1){
        cin >> c;
        c--;
        mi[c]+=s;
      }else{
        for(int j=0;j<k;j++){
          cin >> c;
          c--;
          ma[c]+=s;
        }
      }
    }
    int firstma=0,secondma=0,firstmi=100000,secondmi=10000;
    int firstmai=-1,secondmai=-1,firstmii=-1,secondmii=-1;
    for(int i=0;i<n;i++){
      if(ma[i]+mi[i]>=firstma){
        secondma=firstma;
        secondmai=firstmai;
        firstma=ma[i]+mi[i];
        firstmai=i;
      }else if(ma[i]+mi[i]>=secondma){
        secondma=ma[i]+mi[i];
        secondmai=i;
      }
    }
    for(int i=0;i<n;i++){
      if(mi[i]<=firstmi){
        secondmi=firstmi;
        secondmii=firstmii;a
        firstmi=mi[i];
        firstmii=i;
      }else if(mi[i]<=secondmi){
        secondmi=mi[i];
        secondmii=i;
      }
    }
    if(firstmai!=firstmii){
      cout << firstma-firstmi+1 << endl;
    }else{
      cout << max(firstma-secondmi,secondma-firstmi)+1 << endl;
    }
  }
  return 0;
}

