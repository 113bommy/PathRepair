N,K=map(int,input().split())
a=0
while N>0:
    N//=K
    a+=1
print(a)