u = int(input())
A = list(map(int,input().split()))
count = 0
for a in range(u-1):
  a = A.pop(0)
  if a == A[0]:
    A[0] = -1
    count += 1
print(count)