N,K=map(int,input().split())
c=1
while N>=K**c:
    c+=1
print(c)