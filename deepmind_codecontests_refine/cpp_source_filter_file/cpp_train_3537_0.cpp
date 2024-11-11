//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2607
#include<iostream>
#include<fstream>
#dfine fin cin
using namespace std;

int n = 0;
int d = 0;
int x = 0;

int dp[100001] = {0, };
int fx[10][10];//?????????????????\????????? fx[d][n]


int main()
{
   // ifstream fin("in.txt");

    //input
    fin >> n >> d >> x;
    for(int i = 0; i < d; i++)
    {

        for(int j = 0; j < n; j++)
        {
            fin >> fx[i][j];
        }
    }

    //?????????
    for(int i = 1; i < 100001; i++)
    {
        dp[i] = -10;
    }

    //dp
    for(int day = 0; day < d - 1; day++)
    {
        for(int i = 0; i <= x; i++)dp[i] = i;
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j <= x; j++)
            {

                int sub = j - fx[day][i];
                if(0 <= sub) 
                {

                    dp[j] = max( dp[sub] + fx[day + 1][i], dp[j] );

                }


            }
        }
        int ans_sub = 0;
        for(int k = 0; k <= 100000; k++)
            if(dp[k] > dp[ans_sub]) ans_sub = k;
        x = dp[ans_sub];
    }

    int ans_sub = 0;
    for(int i = 0; i <= 100000; i++)
        if(dp[i] > dp[ans_sub]) ans_sub = i;

    cout << dp[ans_sub] << endl; 

    return 0;
}