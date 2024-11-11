import math

a,b,x,y = list(map(int,input().strip().split()))
ans = 0

g = math.gcd(x,y)

x = x/g
y = y/g

ans = min(math.floor(a/x),math.floor(b/y))

# for w in range(1,a+1):
#     for h in range(1,b+1):
#         if (w/h) == (x/y):
#             ans += 1

print(ans)
