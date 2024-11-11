a,b,k=list(map(int,input().split()))
for i in range(a,a+k):
  if i<=b:
    print(i)

for i in range(b-k+1,b+1):
  if i>=a+k:
    print(i)
