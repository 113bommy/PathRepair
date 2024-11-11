n = int(input())
A = [int(x) for x in input().split()]
B = [0]*n
S = 0
SA = sum(A)
Cnt = 0
Tot = 0
for i in range(n-1):
    S += A[i] 
    if 3*S == 2*SA:
        Tot += Cnt
    if 3*S == SA:
        Cnt += 1
print(Tot)