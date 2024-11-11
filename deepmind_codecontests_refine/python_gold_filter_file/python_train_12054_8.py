N=int(input())
k=0
for i in range(N):
  j=i+1
  if (j%3!=0)and(j%5!=0):
    k=k+j
print(k)
