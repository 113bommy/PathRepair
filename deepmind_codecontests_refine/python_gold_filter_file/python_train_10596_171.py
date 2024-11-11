N,K=map(int,input().split())
i=0
while N>=K**(i+1):
    i+=1
print(i+1)