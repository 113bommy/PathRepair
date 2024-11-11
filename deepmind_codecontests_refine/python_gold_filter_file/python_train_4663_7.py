n=int(input())
ns=int(n**0.5)
nms=int((n-1)**0.5)
p=[n]
for i in range(2,ns+1):
  if n%i==0:
    p.append(i)
    if i!=n//i:
      p.append(n//i)

def chd(x,k):
  while x%k==0:
    x=x//k
  return int((x%k)==1)

count=0
for i in p:
  count+=chd(n,i)
for i in range(2,nms+1):
  if (n-1)%i==0:
    count+=1
    if i!=(n-1)//i:
      count+=1
print(count+1-(n==2))