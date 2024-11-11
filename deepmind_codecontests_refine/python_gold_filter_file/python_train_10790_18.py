l,r,a = map(int, input().split())
less = min(l,r)
more = max(l,r)
diff = more -less
asum=0
if less + a >= more:
    a=abs(diff-a)
    asum=more*2+(a//2)*2

elif less + a < more:
    asum = (less + a)*2

print(asum)
