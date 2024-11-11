n=int(input())
v=list(map(int, input().split()))
a,b=map(int, input().split())
x=0
for i in range(a-1,b-1):
    x+=v[i]
print(x)