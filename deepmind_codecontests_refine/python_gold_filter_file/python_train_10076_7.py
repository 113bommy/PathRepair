N = int(input())
M = 0
for P in map(int, input().split()):
    if P <= N:
        N = P
        M += 1
print(M)