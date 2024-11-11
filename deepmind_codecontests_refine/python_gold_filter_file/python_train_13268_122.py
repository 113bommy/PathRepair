a = int(input())
count = 0
for i in range(a):
    a, b = map(int, input().split())
    a += 2
    if a <= b:
        count += 1
print(count)