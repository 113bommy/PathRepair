#!/usr/bin/python3.5

N = int(input())
L = [int(s) for s in input().split(" ")]
R = [int(s) for s in input().split(" ")]

C = [N - L[i] - R[i] for i in range(0, N)]

for i, x in enumerate(C):
    if C[i] <= 0:
        print("NO")
        exit()

    l = 0
    r = 0

    j = i-1
    while j >= 0:
        if C[j] > C[i]:
            l = l + 1
            
        j = j - 1

    j = i+1
    while j < N:
        if C[j] > C[i]:
            r = r + 1

        j = j + 1

    if L[i] != l or R[i] != r:
        print("NO")
        exit()

print("YES")
for i in range(0, N-1):
    print(C[i], end=" ")

print(C[N-1])

