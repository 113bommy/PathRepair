n = int(input())
a = [int(x) for x in input().split(" ")]

case1 = 0
for i in range(n):
    if a[i] == 0:
        case1 += 1

case2 = 0
for i in range(n):
    if a[i] == 1:
        case2 += 1

final = max(case1, case2)

for i in range(n-1):
    result = 0
    s1 = a[:i+1]
    s2 = a[i+1:]
    for j in s1:
        if j == 0:
            result += 1
    for j in s2:
        if j == 1:
            result += 1
    final = max(final, result)

print(final)