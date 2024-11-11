n=int(input())
a=list(map(int,input().split()))

i=1
count=0

while i<n:
  if a[i]==a[i-1]:
    count+=1
    i+=2
  else:
    i+=1

print(count)