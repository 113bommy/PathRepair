#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int n,a[10],all=1;bad=1;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    all*=3;
    if(a[i]%2==0) {
      bad*=2;
    }
  }
  cout << all-bad << endl;
}