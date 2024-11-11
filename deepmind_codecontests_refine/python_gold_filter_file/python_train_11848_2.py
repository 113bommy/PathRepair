n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=0
t=a[0]
for x in range(n):
    c+=min(t+a[x+1],b[x])
    t=a[x+1] if t>=b[x] else max(0,t+a[x+1]-b[x])
print(c)