#a,b,c = [int(i) for i in input().split()]

import sys
input = sys.stdin.readline

MOD = 10**9+7

n,x = [int(i) for i in input().split()]
s = [int(i) for i in input().split()]
s.sort(reverse=True)

ans = [0]*(x+1)
ans[x] = 1

#print(s)
for i, ss in enumerate(s):
    bairitu = n-i-1
#    print(bairitu)
    for j,xx in enumerate(ans):
#        print(j,xx)
        ans[j] = (xx*bairitu)%MOD
        ans[j%ss] = (ans[j%ss]+xx)%MOD

#    print(ans)

res=0
for j,xx in enumerate(ans):
    res += j*xx 
    res = res%MOD

print(res)



        