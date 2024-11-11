n = int(input())
a = list(input())
l = list(input().split())
j = n
for i in range(n):
    if a[i] < l[int(a[i]) - 1]:
        j = i
        a[i] = l[int(a[i]) - 1]
        break
for i in range(j + 1, n):
    if a[i] <= l[int(a[i]) - 1]:
        a[i] = l[int(a[i]) - 1]
    else:
        break
print(('').join(a))
