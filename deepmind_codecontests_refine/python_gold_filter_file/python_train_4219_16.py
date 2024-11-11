n=int(input())
m=int(input())
k=[]
for i in range(n):
    h=int(input())
    k.append(h)
k.sort()
p=0
s=0
for i in range(n-1,-1,-1):
    if s<m:
        s+=k[i]
        p+=1
print(p)
            