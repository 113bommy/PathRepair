#include <iostream>

using namespace std;

int main()
{
  string s;
  int n, k;
  
  cin >> n >> s >> k;
  
  for (int x = 0; x<n; x++)
  {
    if (s[x] != s[k]) s[x] = "*";
  }
  
  cout << s;
  
}