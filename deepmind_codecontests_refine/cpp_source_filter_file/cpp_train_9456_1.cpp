#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a[4],b[2]={1,-1};
  char c[2]={'+','-'};
  for(int i=0; i<4; i++) {
    a[i]=s[i]-'0';
  }
  for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++) {
      for(int k=0; k<2; k++) {
        if(a[0]+a[1]*b[i]+a[2]*b[j]+a[3]*b[k]==7) {
          cout <<s[0]<<c[i]<<s[1]<<c[j]<<s[2]<<c[k]<<s[3]<<"=7"<<endl;
          return 0;
        }
      }
    }
  }
}
}