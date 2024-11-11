n,t=map(int,input().split())
b=list(map(int,input().split()))
j=s=0
for i in range(n):
    s+=b[i]
    if s>t:
        s-=b[j]
        j+=1
print(n-j)