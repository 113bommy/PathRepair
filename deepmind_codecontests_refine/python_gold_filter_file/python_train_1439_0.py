h,w,k = map(int, input().split())
k -= 1
mod = 1000000007
 
if w==1:
    print(1)
    exit()
 
dp = [[0 for _ in range(w)] for _ in range(h+1)]
dp[0][0] = 1
 
for hi in range(1,h+1):
    for b in range(2**(w-1)):
        judge = False
        for i in range(w-2):
            if (b>>i)&3 == 3:
                judge = True
                break
        if judge:
            continue
 
        perm = [i for i in range(w)]
        for i in range(w-1):
            if (b>>i)&1==1:
                perm[i],perm[i+1] = perm[i+1],perm[i]
        for i in range(w):
            dp[hi][perm[i]]  = (dp[hi][perm[i]]+dp[hi-1][i])%mod
 
print(dp[h][k])