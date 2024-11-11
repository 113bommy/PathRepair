a = int(input())
sum = 0
for i in range(a):
    p, q = map(int, input().split())
    if p + 1 < q:
        sum += 1

print(sum)