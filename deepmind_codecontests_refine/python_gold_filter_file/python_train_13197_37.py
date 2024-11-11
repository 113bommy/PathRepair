n=int(input())
l=list(map(int,input().split()))
l.sort()

sum=l[-1]
for i in range(1,n//2):
  sum+=2*l[-1-i]
if n%2!=0:
  sum+=l[n//2]
print(sum)