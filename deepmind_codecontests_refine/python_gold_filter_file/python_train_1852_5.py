n,x,y=map(int,input().split())
c=[0]*~-n
for i in range(n):
  for j in range(i):
    c[min(~j+i,abs(~j+x)+abs(~i+y))]+=1
print(*c)