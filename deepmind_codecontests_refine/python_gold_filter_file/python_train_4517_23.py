n,k=map(int,input().split())

res = []

i=0
m=n

while i<k:
    res.append(m)
    m-=1
    i+=1

i=0
m=1

while i<(n-k):
    res.append(m)
    m+=1
    i+=1
    
print(' '.join(str(i) for i in res))