from math import ceil

n = int(input())
arr = map(int, input().split())
# n = 2
# arr = [10, 10]
t = []


for i, a in enumerate(arr):
    if a - i <= 0:
        print(i + 1)
        exit()
    a = a - i
    t.append((ceil(a/n), i, a%n))

t.sort()
print(t[0][1] + 1)