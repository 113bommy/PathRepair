n=int(input())
k=int(input())
i=1
for _ in range(n):
  if(i<k):
    i*=2
  else:
    i+=k
print(i)