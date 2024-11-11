import math
def f(n):
    return math.factorial(n)
n,a,b=map(int,input().split())
V=[int(i) for i in input().split()]
V.sort()
if n==a:
  print(sum(V)/a)
  print(1)
else:
  ans=sum(V[n-a:])/a
  count1=V[n-a:].count(V[n-a])
  count2=V[:n-a].count(V[n-a])
  print(ans)
  if count1==a:
    ans2=0
    for i in range(min(count2+1,b-a+1)):
      ans2+=f(count1+count2)/f(count1+i)/f(count2-i)
    print(round(ans2))
  else:
    print(round(f(count1+count2)/f(count1)/f(count2)))