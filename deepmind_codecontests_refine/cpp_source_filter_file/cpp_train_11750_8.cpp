#include <iostream>

using namespace std;

string s;

long long dfs(int n,long long nw,long long tmp){
  long long ans = nw + tmp * 10 + (s[n] - '0');
  if(s.size()-1 == n){
    return ans;
  }
  return (long long)dfs(n + 1, ans, 0) + dfs(n + 1, nw, ans - nw)); 
}

int main()
{
  cin >> s;
  cout << (long long)dfs(0 ,0 ,0) << endl;
}