n,m = map(int,input().split())
a = [int(s) for s in input().split()]
count = 1
for i in range(n - 1):
    if abs(a[i] - a[i + 1]) > m :
        count = 1
    else:
        count += 1
print(count)