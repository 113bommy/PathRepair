#include<iostream>
using namespace std;
int main()
{
  int n,h,w;
  cin >> n;
  cin >> h;
  cin >> w;
  cout >> (n-h+1)*(n-w+1);
  return 0;
}