import math

l = input()
g = (token for token in (l).split())


for i in g:
    n = int(i)
    break
for i in g:
    k = int(i)
    break

a = []
r = float(0)

l = input()
g = (token for token in (l).split())

for i in g:
    a.append(float(i))
    if i == (n-1):
        break



lim = min(k, n-k+1)

#print (a[:lim] + a[n-lim:n])
#print (a[lim:n-lim])

for i in range(lim):
    r += a[i]*(i+1)
    if i < n-i-1:
        r += a[n-i-1]*(i+1)
    
for i in range(lim,n-lim):
    r += a[i]*lim

#print(r)

if not(n==1):
    r /= (n-k+1)

print(r)

    