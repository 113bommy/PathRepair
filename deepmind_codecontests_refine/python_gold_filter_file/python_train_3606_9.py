s=[]
for i in range(2000):
    s+=[i*i]
n=int(input())
a=list(map(int,input().split()))
a.sort()
for i in a:
    if i not in s:
        ans=i    
print(ans)