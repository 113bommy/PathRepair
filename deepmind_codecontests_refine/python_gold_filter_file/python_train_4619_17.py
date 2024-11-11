t=int(input())
s=0
for _ in range(t):
    a,b,c=map(int,input().split())
    if((a+b+c)>=2):
        s=s+1
print(s)