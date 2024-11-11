N=int(input())
s=0
for i in range(1,N):
  s+=(N-1)//i
print(s)