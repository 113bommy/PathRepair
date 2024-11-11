n, t = map(int, input().split())
s = input()
lst = []
a = 0
for _ in s:
    lst.append(_)
for i in range(t):
    for j in range(n - 1):
        if lst[j] == "B" and lst[j + 1] == "G" and a == 0:
            lst[j], lst[j + 1] = lst[j + 1], lst[j]
            a += 1
        else:
            a = 0
    a = 0
for i in lst:
    print(i, end = "")
print()
