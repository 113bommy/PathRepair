#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
 char c[256]; 
 int d[100],i,s,p,f;
 while(true) {
 for (i=0;i<255;i++) c[i]=1;
 i=p=0;
 gets(c);
 if (c[0]=='0') break;
 while(true) {
	 if (c[p+2]==' ' || c[p+2]=='\0') { d[i]=(c[p]-'0')*10+(c[p+1]-'0'); p+=3;}
	 else if (c[p+1]==' ' || c[p+1]=='\0') { d[i]=(c[p]-'0'); p+=2;}
	 if (c[p-1]=='\0') break;
	 i++;
 }
 for (s=0,f=0;i>=0;i--) if (d[i]>0 && d[i]<10) { s+=d[i]; if (d[i]==1) f=1;} else s+=10;
 if (f==1 && s+10<22) s+=10;
 if (s>21) s=0;
 cout << s << endl;
 }
 return 0;
 