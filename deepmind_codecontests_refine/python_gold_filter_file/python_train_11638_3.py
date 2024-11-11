n,k = map(int,input().split())
e=[]
for i in range(k):
  s= int(input())
  l=list(map(int,input().split()))
  e=e+l
r=set(e)
print(n-len(r))