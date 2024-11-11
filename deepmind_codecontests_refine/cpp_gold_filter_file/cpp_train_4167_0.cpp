#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n; double x[100000], y[100000];
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
        scanf("%lf", &y[i]);
    }
    
    pair<double, double> p1[100000], p2[100000];
    
    for(int i = 0; i < n; i++)
    {
        p1[i] = make_pair(x[i], y[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        p2[i] = make_pair(y[i], x[i]);
    }
    
    sort(p1, p1 + n);
    sort(p2, p2 + n);
    
    double sqr_ans = 100000000.0;
    
    const int loops = 111;
    
    for(int i = 0; i < n - 1; i++)
    {
        int r = min(loops, n - i - 1);
        
        for(char j = 1; j <= r; j++)
        {
            double distance_ = (p1[i + j].first - p1[i].first) * (p1[i + j].first - p1[i].first) + (p1[i + j].second - p1[i].second) * (p1[i + j].second - p1[i].second);
        
            sqr_ans = min(distance_, sqr_ans);
        }
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        int r = min(loops, n - i - 1);
        
        for(char j = 1; j <= r; j++)
        {
            double distance_ = (p2[i + j].first - p2[i].first) * (p2[i + j].first - p2[i].first) + (p2[i + j].second - p2[i].second) * (p2[i + j].second - p2[i].second);
        
            sqr_ans = min(distance_, sqr_ans);
        }
    }
    
    printf("%.9f\n", sqrt(sqr_ans));
    
    return 0;
}