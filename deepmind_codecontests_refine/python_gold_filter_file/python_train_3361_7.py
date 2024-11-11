def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) ]))
def invr():
    return(map(int,input().split()))

n = inp()

for i in range(n):
    y = inp()
    l = inlt()
    #print(l)
    l.sort()

    minute = 0

    dp = [0]*402  #minute, val

    first = l[0]

    for j in range(y-1):
        #print(dp[20:])
        new_dp = [200000]*402
        for k in range(402):
            if(k+1 <= l[j]):
                for p in range(k+1,l[j]+1):
                    if(dp[k] + abs(l[j] - p) < new_dp[p]):
                        new_dp[p] = dp[k] + abs(l[j] - p)
            else:
                if(dp[k] + abs(l[j] - k - 1) < new_dp[p]):
                    new_dp[k+1] = dp[k] + abs(l[j] - k - 1)
        dp = new_dp.copy()
    #print(dp)
    new_dp = [200000] * 402
    for j in range(402):
        if(j < l[-1]):
            if(dp[j] < new_dp[l[-1]]):
                new_dp[l[-1]] = dp[j]
            #print(new_dp[l[-1]])
        else:
            if(dp[j] + abs(l[-1] - j - 1)<new_dp[l[-1]]):
                new_dp[l[-1]] = dp[j] + abs(l[-1] - j - 1)
    #print(new_dp)
    new_dp.sort()
    print(min(new_dp))
