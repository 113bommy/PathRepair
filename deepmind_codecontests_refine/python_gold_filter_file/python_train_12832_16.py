#Codeforces1399C
t = int(input())
for i in range(t):
    n = int(input())

    lst = input().split()
    lst1 = [0] * (n + 1)
    for i in range(n):
        lst1[int(lst[i])] += 1

    lst2 = [0] * (2 * n + 1)
    for j in range(1, n + 1):
        for k in range(j + 1, n + 1):
            lst2[j + k] += (min(lst1[j], lst1[k]))
    for j in range(n + 1):
        lst2[j * 2] += int(lst1[j] / 2)
    print(max(lst2))
