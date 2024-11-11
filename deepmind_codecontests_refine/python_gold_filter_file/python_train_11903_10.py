from bisect import bisect_left as lower
from sys import stdin
input = stdin.readline
k = int(input())
s = [int(i) for i in list(input().strip())]
n = len(s)
if k==0:
    prev = 0
    ans = 0
    for i in range(n):
        if s[i]==0:
            prev+=1
            ans+=prev
        else:
            prev=0
    print(ans)
    exit()
l = [0]
for i in range(n):
    l.append(l[-1]+s[i])


ans = 0
#print(l)
prev = -1
dp = [n+1]*(sum(s)+2)
for i in range(n+1):
    if prev!=l[i]:
        dp[l[i]]=i
    prev = l[i]

#print(dp)
summ = sum(s)
for i in range(summ):
    if i+k+1>summ+1:
        break
    ax,ay = dp[i],   dp[i+1]
    bx,by = dp[i+k], dp[i+k+1]
    #print(ax,ay,bx,by)
    if n+1 not in [ax, bx]:
        ans += (ay-ax)*(by-bx)
print(ans)



