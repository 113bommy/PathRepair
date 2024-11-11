#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n,i,j;
  cin >> n;
  vector<int> v(n);
  for(i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v.rbegin(),v.rend());
  long long r = 1;
  for(i=0;i<n&&(j=a[i]-i/4)>0;i++)r+=j;
  cout << r << endl;
  return 0;
}