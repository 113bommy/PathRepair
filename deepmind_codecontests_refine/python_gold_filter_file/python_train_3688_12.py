n = int(input())
m = list(map(int, input().split()))
a, b = map(int, input().split())
h = 0
for i in range(a - 1, b - 1):
    h += m[i]
print(h)