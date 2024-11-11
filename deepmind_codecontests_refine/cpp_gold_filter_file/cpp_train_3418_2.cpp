#include<iostream>
using namespace std;
int main(){int c[9];for(int i=0;i<9;i++)cin>>c[i];cout<<(((c[0]+c[4]-c[1]-c[3])|(c[0]+c[5]-c[2]-c[3])|(c[0]+c[7]-c[1]-c[6])|(c[0]+c[8]-c[2]-c[6]))?"No":"Yes")<<endl;}