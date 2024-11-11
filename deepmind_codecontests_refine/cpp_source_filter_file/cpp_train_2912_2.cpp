include<iostream>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;

bool check(int n)
{
  stringstream ss;
  ss << n;
  string s = ss.str();
  string rs(s.rbegin(),s.rend());
  return s == rs;
}

int main()
{
  vector<int> vec;
  for(int i=1;i<=10000;i++)
    if(check(i))
      vec.push_back(i);
      
  int n;
  cin >> n;
  vector<int>::iterator it = lower_bound(vec.begin(),vec.end(),n);
  if(*it == n)
    cout << n << endl;
  else if(abs(*(it-1)-n) == abs((*it)-n))
    cout << *(it-1) << endl;
  else 
    (abs(*(it-1)-n) < abs((*it)-n))?cout << *(it-1) << endl:cout << (*it) << endl;
  return 0;
}