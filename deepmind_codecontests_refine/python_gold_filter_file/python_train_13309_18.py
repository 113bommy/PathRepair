n = int(input())
a = list(map(int, input().split()))

result = []

for i in range(2):
    num = 0
    r = 0
    for j in range(len(a)):
        num += a[j]
        if (j + i) % 2 == 0:
            if num <= 0:
                r -= num - 1
                num = 1

        else:
            if num >= 0:
                r += num + 1
                num = -1

    result.append(r)

print(min(result))
