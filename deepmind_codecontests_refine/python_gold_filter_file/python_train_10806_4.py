n = int(input())
v = list(map(int,input().split()))
c = list(map(int,input().split()))

ans = 0
for x,y in zip(v,c):
    ans += max(0,x-y)
print(ans)