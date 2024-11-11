n=int(input())
ncount=0
for i in range(n):
    a,b=map(int,input().split())
    if b-a>=2:
        ncount+=1
print(ncount)