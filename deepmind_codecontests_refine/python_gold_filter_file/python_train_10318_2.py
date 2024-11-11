from sys import stdin
from collections import Counter
input = stdin.readline

n = int(input())
a = [int(x) for x in input().split()]
c = Counter(a)

single = []
multiple_value = -1
multiple_count = -1
for value, count in c.items():
    if count == 1:
        single.append(value)
    elif count >= 3 and multiple_value == -1:
        multiple_value = value
        multiple_count = count

if len(single) % 2 == 0:
    group_a = set(single[:len(single) // 2])
    ans = []
    for i in range(n):
        if a[i] in group_a:
            ans.append("A")
        else:
            ans.append("B")
    print("YES")
    print(*ans, sep="")

elif multiple_value != -1:
    group_a = set(single[:len(single) // 2])
    ans = []
    for i in range(n):
        if a[i] == multiple_value:
            if multiple_count == 1:
                ans.append("A")
            else:
                ans.append("B")
            multiple_count -= 1
        elif a[i] in group_a:
            ans.append("A")
        else:
            ans.append("B")
    print("YES")
    print(*ans, sep="")

else:
    print("NO")