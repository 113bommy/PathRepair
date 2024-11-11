from sys import setrecursionlimit
setrecursionlimit(10**6)

numSlimes = int(input())  # Get input stdin

row = list()

aSlime = 1

for i in range(numSlimes):
    row.append(aSlime)
    while len(row) >= 2 and (row[-2] == row[-1]):
        v1 = row.pop()
        v2 = row.pop()
        v = v1 + 1
        row.append(v)

print(* row)