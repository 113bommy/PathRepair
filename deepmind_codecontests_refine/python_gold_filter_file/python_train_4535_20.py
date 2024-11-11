

n = int(input())

A = sorted([int(x) for x in input().split()])

print(A[(len(A) - 1) // 2])
