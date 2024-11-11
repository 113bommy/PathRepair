#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int n,a,M=0,b[100010]={0};
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a;
    b[a]++;
  }
  for(int i=1; i<=100000; i++) {
    M=max(M,b[i-1]+b[i]+b[i+1]);
  }
  cout << M << endl;
}