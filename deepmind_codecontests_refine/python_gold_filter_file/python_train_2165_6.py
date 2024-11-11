N=int(input())
A=map(int,input().split())
i=1
for a in A:
  if a==i: i+=1
i-=1
print(N-i if i>0 else -1)
