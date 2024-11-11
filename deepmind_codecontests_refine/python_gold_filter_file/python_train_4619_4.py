t=int(input())
co=0
for _ in range(t):
    a,b,c=map(int,input().split())
    if a+b+c>=2:
        co=co+1
print(co)