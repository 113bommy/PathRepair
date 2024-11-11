for i in range(int(input())):
    r, l = map(int,input().split())
    if l%2==0:
        print(str(l//2) + " " + str(l))
    else:
        print(str((l-1)//2) + " " + str(l-1))