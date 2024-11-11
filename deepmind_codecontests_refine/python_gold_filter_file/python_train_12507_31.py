n = int(input())
a = []
for j in range(n):
    l, r = map(int, input().split())
    a.append(l)
    a.append(r)
k = int(input())
if k != 1:
    for i in range(len(a)):
        if a[i] < k and k <= a[i + 1]:
            print((len(a) -i) // 2)
else:
    print(n)