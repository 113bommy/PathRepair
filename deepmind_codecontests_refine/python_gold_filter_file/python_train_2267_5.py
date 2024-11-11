x,n = list(map(int,input().split()))
p = list(map(int,input().split()))

ans=1000
for i in range(-105,102):
    if i in p:
        continue
    if abs(x-ans)>abs(i-x):
        ans=i
print(ans)