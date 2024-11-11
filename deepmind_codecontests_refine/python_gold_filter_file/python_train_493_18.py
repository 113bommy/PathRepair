N=int(input())
Ans=0

for i in range(1,N):
  Ans+=(N-1)//i

print(Ans)
