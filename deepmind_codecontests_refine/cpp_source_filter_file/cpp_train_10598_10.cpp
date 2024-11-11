#include <bits/stdc++.h>
using namespace std;

int main() {
  int r d x;
  cin>>r>>d>>x;
  for(int i=0;i<10;i++){
    x=x*r-d;
    cout<<x<<endl;
  }
}
