import bisect
input()
given = sorted([int(x) for x in input().split()])
for i in [int(x) for x in input().split()]:
    print(bisect.bisect(given, i), end=" ")
