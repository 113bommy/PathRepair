#include<iostream>
#include<vector>
 
using namespace std;
 
int main(){
 
    int r,c;
 
    while(cin>>r>>c,r,c){
      
        if(r*c%2==0){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}