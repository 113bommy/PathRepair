inf = float("INF")
x,y,z,k=map(int,input().split())
dp=[0]*3000
l =[]
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
for i in a:
  for j in b:
    l.append(i+j)
l.sort()
l = l[::-1]
t =[]
for i in l[:k]:
  for j in c:
    t.append(i+j)
t.sort()
t = t[::-1]
for i ,n in enumerate(t):
  print(n)
  if i == k-1:break