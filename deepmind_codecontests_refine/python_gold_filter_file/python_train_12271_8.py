for i in range(int(input())):
    a = sorted(map(int,input().split()),reverse = True)
    if a[0]**2 == a[1]**2 + a[2]**2:
        print("YES")
    else:
        print("NO")