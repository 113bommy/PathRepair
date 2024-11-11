for _ in range(int(input())):
    a=[int(i) for i in input().split()]
    a.sort()
    if(a[0]+a[1]>=a[2]-1):
        print("Yes")
    else:
        print("No")