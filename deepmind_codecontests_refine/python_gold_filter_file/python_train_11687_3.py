import math
######################################################
# ps template
def mi(): return map(int, input().split())
def ii(): return int(input())
def li(): return list(map(int, input().split()))
def si(): return input().split()

#######################################################
t = ii()
for _ in range(t):
    n, k, l = mi()
    a = li()
    dp = [ 0 for i in range(n)]
    ans = True
    rev = False
    if a[0]+k<=l:
        dp[0] = 'F'
    elif a[0]<=l:
        dp[0] = l - a[0]
        if dp[0] > 0:
            rev = True
        else:
            rev = False
    else:
        dp[0] = -1
    for i in range(1,n):
        if dp[i-1]==-1 or a[i]>l:
            ans = False
            break
        if a[i]+k<=l:
            dp[i] = 'F'
        elif dp[i-1]=='F':
            dp[i] = l - a[i]
            if dp[i]>0:
                rev = True
            else:
                rev = False
        elif rev:
            if l-a[i]<=dp[i-1]-1:
                dp[i] = l - a[i]
                if dp[i]>0:
                    rev = True
                else:
                    rev = False
            else:
                dp[i] = dp[i-1] - 1
                if dp[i]>0:
                    rev = True
                else:
                    rev = False
        elif dp[i-1]+1+a[i]<=l:
            dp[i] = dp[i-1]+1
            if dp[i] == k:
                rev= True
        else:
            ans = False
            break
    #print(dp)
    if ans:
        print("Yes")
    else:
        print('No')

