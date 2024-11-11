w, b = [int(i) for i in input().split()]


dp = [[-1 for i in range(b+1)] for j in range(w+1)]

def f(w, b):
    #if w<0 or b<0:
    #    return 0
    if w==0 and b==0:
        return 0
    if b<=0:
        return 1
    if w == 0:
        return 0
    if dp[w][b] != -1:
        return dp[w][b]
    ans = w/(w+b)
    if w>=1 and b>=2:
        ans += (b/(w+b))*((b-1)/(w+b-1))*((w/(w+b-2)) * f(w-1, b-2))
    if b>=3:
        ans += (b/(w+b))*((b-1)/(w+b-1))*((b-2)/(w+b-2))* f(w, b-3)
    dp[w][b] = ans
    return ans

print(f(w, b))
