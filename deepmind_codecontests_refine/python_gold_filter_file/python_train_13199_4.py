N=int(input())
for i in range(int(N**0.5),0,-1):
  if N%i==0:
    d=int(N//i)
    break
print(i+d-2)