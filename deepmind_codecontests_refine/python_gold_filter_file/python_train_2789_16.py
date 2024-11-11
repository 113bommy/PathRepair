N = int(input())
L = list(map(int,input().split()))

s = sum(L)
p = 0
for a in L:
 p += a*a

ans=(s*s-p)/2

print(int(ans))