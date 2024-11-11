N,K=map(int,input().split())
s=0
while N>0:
    N=N//K
    s+=1
print(s)