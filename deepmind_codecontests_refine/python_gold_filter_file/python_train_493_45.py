N=int(input())
a=0
for i in range(1,N-1):
  a+=(N-1)//i
print(a+1)