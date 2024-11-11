import sys
#input = sys.stdin.buffer.readline

INF = 100000000
n1 , n2 , k1 , k2 = [int(i) for i in input().split()]
global K1; global K2
K1 = k1  ; K2 = k2
elephant = [ [-1 for j in range(n2+1) ] for i in range(n1+1) ]
dog      = [ [-1 for j in range(n2+1) ] for i in range(n1+1) ]
def rep(i,j,is_elephant):
    if i == 0 and j == 0 :return 1

    if     is_elephant and elephant[i][j] != -1 : return elephant[i][j]
    if not is_elephant and dog[i][j]      != -1 : return dog[i][j]

    # Select elephant and add some dogs
    if is_elephant:
        ans = 0
        for k in range(1,min(j,K2) + 1):
            ans += rep(i,j-k,False) % INF
        ans            = ans % INF
        elephant[i][j] = ans

    # Select dog and add some elephant
    else:
        ans = 0
        for k in range(1,min(i,K1) + 1):
            ans += rep(i-k,j,True) % INF
        ans       = ans % INF
        dog[i][j] = ans
        
    return ans

print( (rep(n1,n2,True) + rep(n1,n2,False)) % INF)
