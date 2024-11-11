n = input()
S = set(map(int, input().split()))
q = input()
T = set(map(int, input().split()))
C = 0

for i in T:
    if i in S:
        C += 1

print(C)