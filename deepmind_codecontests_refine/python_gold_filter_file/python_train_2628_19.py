for i in range(int(input())):
    m, n = map(int, input().split())
    if m ==1:
        print("YES")
    elif n ==1:
        print("YES")
    elif m*n==4:
        print("YES")
    else:
        print("NO")