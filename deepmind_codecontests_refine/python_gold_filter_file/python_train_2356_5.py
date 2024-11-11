n = int(input())
a = list(map(int, input().split()))
e = 0
for i in range(1, len(a) - 1):
    if a[i] > a[i - 1] and a[i] > a[i + 1]:
        e += 1
    elif a[i] < a[i - 1] and a[i] < a[i + 1]:
        e += 1
print(e)
        