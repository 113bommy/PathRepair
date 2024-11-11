from math import ceil, sqrt, floor

n = int(input())
for i in range(n):
    _ = int(input())
    for j in range(2) :
        print(*sorted(list(map(int, input().split()))))