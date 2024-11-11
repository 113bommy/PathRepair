N=int(input())
*P,=map(int,input().split())

i=c=0
while i<N:
  if P[i]==i+1:
    c+=1
    i+=1
  i+=1
print(c)