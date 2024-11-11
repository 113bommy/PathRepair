#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 605;
const int maxk = 18;
const int maxmask = 131077;
const long long int INF = 1000000000000000000;
//const int INF = 1e9;

int in[maxn][maxn];
int piece_top[maxk][maxn];
int piece_bot[maxk][maxn];
long long int difference[maxk][maxk]; // gdzie pierwszy to top, a drugi to bot
long long int dp[maxmask][maxk];
int prev[maxmask][maxk];
int position[maxk];
vector<int> path;

int q, h, w, k, pieceh;

void writepieces()
{
    printf("piece_top:\n");
    for(int i = 0; i < k; i++)
    {
        printf("%d: ", i);
        for(int j = 0; j < w; j++)
        {
            printf("%d ", piece_top[i][j]);
        }
        printf("\n");
    }

    printf("piece_bot:\n");
    for(int i = 0; i < k; i++)
    {
        printf("%d: ", i);
        for(int j = 0; j < w; j++)
        {
            printf("%d ", piece_bot[i][j]);
        }
        printf("\n");
    }
}

void writediff()
{
    printf("wypisywaniediffa:\n");
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            printf("difference[ %d ][ %d ]: %d\n", i, j, difference[i][j]);
        }
    }
}

bool wmasce( int mask, int x )
{
    return ( ( mask & ( 1 << x ) ) == ( 1 << x ) );
}

long long int count_difference( int x, int y, int decrease ) // pierwsze to top, drugie to bot
{
    long long int res = 0;
    for( int i = 0; i < w; i++)
    {
        int now = 100, now2 = 50, it = i;
        while( now > 0 && it < w )
        {
            res += abs( piece_top[x][i] - piece_bot[y][it] ) * now;
            res += abs( piece_top[x][i] - in[ (y + 1) * pieceh - 2 ][it] ) * now2;
            now -= decrease;
            now2 = max( 0, now2 - decrease );
            it ++;
        }

        now = 100 - decrease;
        now2 = 50 - decrease;
        it = i - 1;
        while( now > 0 && it >= 0 )
        {
            res += abs( piece_top[x][i] - piece_bot[y][it] ) * now;
            res += abs( piece_top[x][i] - in[ (y + 1) * pieceh - 2 ][it] ) * now2;
            now -= decrease;
            now2 = max( 0, now2 - decrease);
            it --;
        }
    }

    return res;
}

void findpath( int u, int mask )
{
    if( u == - 1 )
    {
        return;
    }
    //printf("U:%d, mask:%d\n", u, mask );
    path.push_back( u );

    findpath( prev[mask][u], mask ^ ( 1 << u ) );
    return;
}

void query()
{
    scanf("%d%d%d", &h, &w, &k);

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            scanf("%d", &in[i][j]);
        }
    }

    pieceh = h / k;

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < w; j++)
        {
            piece_top[i][j] = in[ i * pieceh ][j];
        }

        for(int j = 0; j < w; j++)
        {
            piece_bot[i][j] = in[ (i + 1) * pieceh - 1 ][j];
        }
    }

    //writepieces();

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            difference[i][j] = count_difference( i, j, 14 );
        }
    }

    //writediff();

    for(int mask = 0; mask < ( 1 << k ); mask++)
    {
        for(int i = 0; i < k; i++)
        {
            dp[mask][i] = INF;
            prev[mask][i] = -1;
        }
    }

    for(int mask = 0; mask < ( 1 << k ); mask++)
    {
        for(int i = 0; i < k; i++)
        {
            if( __builtin_popcount(mask) == 1 && wmasce( mask, i ) )
            {
                //printf("popcount:1, mask:%d, i:%d\n", mask, i);
                dp[mask][i] = 0;
            }

            if( __builtin_popcount(mask) > 1 && wmasce( mask, i ) )
            {
                for( int j = 0; j < k; j++)
                {
                    if( !wmasce( mask ^ ( 1 << i ), j ) || j == i )
                    {
                        //printf("mask:%d, i:%d, j:%d, niewmasce :/\n", mask, i, j );
                        continue;
                    }

                    if( dp[mask ^ ( 1 << i ) ][j] + difference[j][i] < dp[mask][i] )
                    {
                        dp[mask][i] = dp[mask ^ (1 << i) ][j] + difference[j][i];
                        prev[mask][i] = j;
                    }
                }
            }

            //printf("mask:%d, i:%d, dp[mask][i]:%d, prev[mask][i]:%d \n", mask, i, dp[mask][i], prev[mask][i] );
        }
    }

    long long int endval = INF, end = -1;
    for(int i = 0; i < k; i++)
    {
        if( dp[ ( 1 << k ) - 1 ][i] < endval )
        {
            endval = dp[ ( 1 << k ) - 1][i];
            end = i;
        }
    }

    findpath( end, ( 1 << k ) - 1 );

    //reverse( path.begin(), path.end() );

    for(int i = 0; i < path.size(); i++)
    {
        position[ path[i] + 1 ] = i + 1;
    }

    for( int i = 1; i <= k; i++)
    {
        printf("%d ", position[i]);
    }
    printf("\n");
}

void czysc()
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            in[i][j] = 0;
        }
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < w; j++)
        {
            piece_top[i][j] = 0;
            piece_bot[i][j] = 0;
        }
    }

    for(int mask = 0; mask < ( 1 << k ); mask++)
    {
        for(int i = 0; i < k; i++)
        {
            dp[mask][i] = INF;
            prev[mask][i] = -1;
        }
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            difference[i][j] = 0;
        }
    }

    path.clear();
}

int main()
{
    scanf("%d", &q);

    /*query();
    czysc();
    query();
    return 0;*/

    while( q-- )
    {
        query();

        czysc();
    }
}
