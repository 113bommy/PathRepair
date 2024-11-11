N=int(input())
A=list(map(int,input().split()))
l=[abs(i)  for i in A]
cnt=0
for i in A:
    if(i<0):
        cnt+=1
if cnt%2==0:
    print(sum(l))
else:
    print(sum(l)-2*min(l))
