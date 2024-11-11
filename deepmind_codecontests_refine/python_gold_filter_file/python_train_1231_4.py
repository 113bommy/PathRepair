import math
n,h = map(int,input().split())
A = 0; b = []; ans = 0
for _ in range(n):
    u,v = map(int,input().split())
    A = max(A,u); b.append(v)

for B in sorted(b,key=lambda x:-x):
    if h <= 0 or B <= A:break
    h -= B
    ans += 1
print(max(0,math.ceil(h/A)) + ans)