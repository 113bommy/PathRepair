n=int(input())
L=list(map(int,input().split(' ')))
L=sorted(L,reverse=True)
i=0

while L[i]>=0 and int(L[i]**(1/2))-L[i]**(1/2)==0:
  i=i+1
print(L[i])