n = int(input())
a = sorted(map(int, input().split()))
b = [0] * len(a)
k = l = 0
if sum(a) % 2 != 0:
    for i in a:
        if i % 2 != 0:
            b[l] = i
            l += 1
        else:
            k += i
    for i in range(1, len(b)):
        k += b[i]
    print(k)
else:
    print(sum(a))
