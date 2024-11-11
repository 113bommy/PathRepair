#include<bits/stdc++.h>
using namespace std;

vector<bool> solve(int n, vector<bool> &s)
{
	for(int i = 0; i < 2; i++)
    {
    	for(int j = 0; j < 2; j++)
        {
        	vector<bool> res(n);
          	res[0] = i;
          	res[1] = j;
          	for(int k = 2; k < n; k++)
            	res[k] = (res[k - 2] ^ res[k - 1] ^ s[k - 1]);
          	if (s[n - 1] == (res[n - 2] ^ res[n - 1] ^ res[0]) &&
                    s[0] == (res[n - 1] ^ res[0] ^ res[1]))
                return res;
        }      
    }
  	return vector<bool>();
}

int main()
{
  	int n;
  	cin>>n;
  	vector<bool> v(n);
  	for(int i = 0; i < n; i++)
    {
    	char c;
      	cin>>c;
      	v[i] = (c == 'o');
    }
  	vector<bool> res = solve(n, v);
  	if(res.empty())
      	cout <<-1<<"\n";
  	else
    {
    	for (bool p : res) 
          cout << (p ? 'S' : 'W');
        cout << "\n";
    }
	return 0;
}
