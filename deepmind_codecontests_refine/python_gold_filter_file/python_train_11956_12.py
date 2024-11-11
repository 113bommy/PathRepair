n = int(input())
k = int(input())
x = list(map(int, input().split()))
d = 0
for i in x:
    d += min(i, k-i) * 2

print(d)