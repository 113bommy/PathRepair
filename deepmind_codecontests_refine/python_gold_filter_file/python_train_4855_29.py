n = int(input())

ls = []
k = 1
z = 0
while(z<=n):
    z = (2**k-1)*(2**(k-1))
    if z>n:
        break
    ls.append(z)
    k+=1

t = len(ls)-1
while(t>=0):
    if n%ls[t]==0:
        res = ls[t]
        break
    else:
        t-=1

print(res)