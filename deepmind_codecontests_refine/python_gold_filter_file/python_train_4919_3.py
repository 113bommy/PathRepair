from sys import stdin,stdout
#for _ in range(int(stdin.readline())):
    # n=int(stdin.readline())
n,s=list(map(int,stdin.readline().split()))
ans=[]
f=0
for i in range(n-1):
     s=s-2
     ans.append(2)
     if s==1 or s<=0:
          f=1
          break
ans.append(s)
if f==1 or ans[-1]==1:
     print('NO')
else:
    # ans.append(s)
     print('YES')
     print(*ans)
     print('1')
