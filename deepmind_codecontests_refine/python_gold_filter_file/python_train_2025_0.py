n = int(input())
a = list(map(int, input().split()))
i = 1
b = [a[0]]
while i < len(a):
    if a[i-1] <= a[i]:
        b += [a[i]]
    else:
        break
    i += 1
a = a[i:]
# print(a, b)
if a == sorted(a) and (len(a) == 0 or a[-1] <= b[0]):
    print(len(a))
else:
    print(-1)

