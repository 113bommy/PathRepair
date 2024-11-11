import bisect 

q,w,x,y,z = map(int,input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
ans = 0
try:
    for i in range(z+1):
        t = bisect.bisect_left(b,a[i]+x)
        tt = t+z-i
        ans = max(ans,b[tt])
        # print(i,t,tt,b[tt]+y)
    print(ans+y)   
except:
    print(-1)