n = int(input())
ans = 0
l = set([])
for i in range(2**10+1):
    t = '0'*10
    t = list(t)
    for j in range(0,10):
        if ((i&(2**j))>0):
            t[j]=1 
    t1 = t[:]
    t = ''
    for k in t1:
        t+=str(k)
    l.add(int(t))

for i in l:
    if (i<=n and i>0):
        
        ans+=1 
print(ans)