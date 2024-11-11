a, b=map(int, input().split())
l=[int(x) for x in input().split()]
d=0
for i in range(1, 2*a+1, 2):
    if l[i]-1>l[i-1] and l[i]-1>l[i+1]:
        d+=1
        l[i]-=1
    if d==b:
        break
print(*l)