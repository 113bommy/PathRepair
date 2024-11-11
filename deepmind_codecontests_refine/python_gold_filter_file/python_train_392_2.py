n, *a = map(int, open(0).read().split())
a2 = sorted(a)[-2:]
for i in range(n):
    if a[i]==a2[1]:
        print(a2[0])
    else:
        print(a2[1])