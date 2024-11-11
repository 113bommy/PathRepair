#include <iostream>
#include <vector>
#define rep(i,n) for(int i= 0; i<n;i++)
#define loop(i,f,n) for(int i = f; i<n; i++)
#define MAX 1000000
using namespace std;

int main(){
	
	int n,num = 0;
	vector<int>stac(MAX,0);
	cin >> n;
	int tuki = 0;
	int r;
	int cc = 0;
	bool checking = true;
	rep(i,n)
	{
		int temp;
		char s;
		cin >> s >> temp;
		num +=temp;
		if(s == '(')
		{	
			tuki+= temp;
			cc+= temp;
		}
		else if(s == ')')
		{
			tuki -= temp;
			cc-= temp;
		}
		if(cc < 0)
		  checking = false;
	}
//		cout << checking << endl;
		/*?\???°?????¨??????????????¶s?????????*/
		if(cc <0 || checking == false)
		{	
			cout << "NO" << endl;
			return 0;
		}		
		if(num % 2)
		{
			cout << "NO" << endl;
			return 0;
		}

		if(tuki == 0)
		{
			cout << "YES" << endl;
			return 0;
		}
		else 
			cout << "NO"<< endl;
		return 0;


	}