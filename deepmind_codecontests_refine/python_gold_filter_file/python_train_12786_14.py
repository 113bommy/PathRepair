N=int(input())
s=N//4
for i in range(s+1):
  if (N-4*i)%7==0:
    print("Yes")
    break
else:
    print("No")