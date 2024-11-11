n,x,y=map(int,input().split())
l=[0]*~-n
for i in range(1,n):
 for j in range(i):l[min(~j+i,abs(~j+x)+abs(~i+y))]+=1
print(*l)