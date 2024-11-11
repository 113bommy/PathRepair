n = int(input())
l = [int(x) for x in input().split()]

for i in range(n):
    a = l[i]
    j = i - 1

    while j >= 0 and l[j] > a:
        l[j+1] = l[j]
        j = j - 1

    l[j+1] = a
    print(*l)