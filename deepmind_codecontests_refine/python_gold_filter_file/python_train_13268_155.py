n=int(input())
c=0
for i in range(n):
    j,k=map(int,input().split())
    if k-j>=2:
        c+=1
print(c)