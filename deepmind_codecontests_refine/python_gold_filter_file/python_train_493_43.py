N=int(input())
cnt=0
for i in range(1,N):
  cnt+=(N-1)//i
print(cnt)