N=int(input())
d=N//4
for i in range(d+1):
  if (N-4*i)%7==0:
    print("Yes")
    break
else:
  print("No")