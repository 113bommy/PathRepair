#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
int main() {
  long long n,ans=0;
  cin >> n;
  n++;
  while(n>9) {
    n/=10;
    ans++;
  }
  cout << n-1+ans*9 << endl;
}
