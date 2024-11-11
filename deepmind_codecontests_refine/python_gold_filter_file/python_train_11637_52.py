import sys
pin=sys.stdin.readline

N=int(pin())
A=list(map(int,pin().split()))
B=list(map(int,pin().split()))
C=list(reversed(B))

for i in range(N):
  if A[i]==C[i]:
    break
else:
  print("Yes")
  for k in C:
    sys.stdout.write(f"{k} ")
  print()
  sys.exit()
D=B[N//2:]+B[:N//2]
for j in range(N):
  if A[j]==D[j]:
    print("No")
    break
else:
  print("Yes")
  for l in D:
    sys.stdout.write(f"{l} ")
  print()
  sys.exit()
