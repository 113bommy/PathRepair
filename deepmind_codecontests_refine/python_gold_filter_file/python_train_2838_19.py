t = int(input())
for _ in range(t):
    a = list(map(int,input().split()))
    a.sort()
    if a[1] == a[2]:
        print("YES")
        print(str(a[0]) + ' ' + str(a[0]) + ' ' + str(a[1]))
    else:
        print("NO")