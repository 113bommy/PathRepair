#include<bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    int m,f,r;
    string am;
    
    cin>>m>>f>>r;
    if(m==-1 && f==-1 && r==-1)break;
    if(m==-1 || f==-1)am="F";
    else if(m+f<30)am=="F";
    else if(m+f<50 && r>=50)am=="C";
    else if(m+f<50)am=="D";
    else if(m+f<65)am=="C";
    else if(m+f<80)am=="B";
    else {am=="A"}

    cout<<am<<endl;
  }	   
  
}
