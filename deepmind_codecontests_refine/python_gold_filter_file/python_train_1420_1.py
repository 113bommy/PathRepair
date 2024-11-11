import sys
input = sys.stdin.readline

n = int(input())
lst = sorted(list(map(int, input().split())))
rep, maxRep = 1, 1
for i in range(1, n):
    if lst[i] == lst[i-1]:
        rep += 1
        maxRep = max(maxRep, rep)
    else:
        rep = 1
print(maxRep)