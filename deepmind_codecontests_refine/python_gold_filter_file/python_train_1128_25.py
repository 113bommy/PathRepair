n=int(input())
a=list(map(int,input().split()))
b=[0]*9
for i in a:
  b[min(i//400,8)]+=1
print(max(8-b[:8].count(0),1),8-b[:8].count(0)+b[8])