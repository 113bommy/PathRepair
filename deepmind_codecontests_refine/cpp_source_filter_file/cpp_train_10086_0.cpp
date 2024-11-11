clude <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && (n >=0))  {
        int sum = 1150;
        if(n > 10 && n <= 20)
            sum += (n - 10) * 125;
        if(n > 20 && n <= 30)
            sum += 10 * 125 + (n - 20) * 140;
        if(n > 30)
            sum += 10 * 125 + 10 * 140 + (n - 30) * 160;
        cout << 4280 - sum << endl; 
    }
}