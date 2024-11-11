n = int(input())
arr = [int(x) for x in input().split()]
arr.sort()
for x in arr:
    print(x, end = ' ')
    