n,t=map(int,input().split())
l=list(map(int,input().split()))
j=s=0
for i in range(n):
    s+=l[i]
    if s>t:
        s-=l[j]
        j+=1
print(n-j)