N = int(input())
P = list(map(int, input().split()))
CNT = 0
for i in range(N):
  if P[i] != i+1:
    CNT += 1
print('YES' if  CNT <=  2 else 'NO')