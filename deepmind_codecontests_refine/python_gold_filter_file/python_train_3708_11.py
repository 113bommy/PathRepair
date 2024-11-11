n,p,q,r = map(int,input().split(' '))
a = list(map(int,input().split(' ')))
maxi = -1000000000000000000000
b = [a[0]]
c = [a[-1]]
if p>0:
  for i in range(1,n):
    b.append(max(b[i-1],a[i]))
else:
  for i in range(1,n):
    b.append(min(b[i-1],a[i]))

if r>0:
  for i in range(1,n):
    c.append(max(c[i-1],a[-i-1]))    
else:
  for i in range(1,n):
    c.append(min(c[i-1],a[-i-1]))
    

for j in range(n):
  s = p*b[j] + q*a[j] + r*c[-j-1]
  maxi = max(maxi,s)

print(maxi)
##print(' '.join(map(str,b)))
##print(' '.join(map(str,c)))
