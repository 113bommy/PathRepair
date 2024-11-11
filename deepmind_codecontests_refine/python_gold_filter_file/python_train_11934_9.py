from math import gcd
N = int(input())
List = [int(x) for x in input().split()]
One = List.count(1)
if(One>0):
    print(N - One)
else:
    Min = 10**9
    for i in range(N):
        GCD = List[i]
        for j in range(i+1,N):
            GCD = gcd(GCD,List[j])
            if(GCD == 1):
                Min = min(j - i, Min)
                break
        
    if(Min == 10**9):
        print(-1)
    else:
        print(Min + N- 1)