n=int(input())
l=list(map(int,input().split()))
s=sum(l)
m=[]
for i in range(n):
    m.append(abs(s-sum(l[:i+1])*2))
print(min(m))