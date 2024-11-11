n=int(input())
m=int(input())
a=[]
for i in range(n):
    k=int(input())
    a.append(k)
a=sorted(a,reverse=True)
k=0
ii=0
for i in a:
    if k>=m:
        break
    else:
        k+=i
        ii+=1
print(ii)