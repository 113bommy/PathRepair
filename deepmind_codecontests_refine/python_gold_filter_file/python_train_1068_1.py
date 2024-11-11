t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    
    aS = set(a)
    u = len(aS)
    
    answer = 0
    
    if 0 not in aS:
        u -= min(k - 1, u - 1)
        answer += 1
    
    k -= 1
    
    if k == 0:
        if u == 1:
            print(answer)
        else:
            print(-1)
    else:
        allSame = (u + k - 2) // k
        print(answer + allSame)