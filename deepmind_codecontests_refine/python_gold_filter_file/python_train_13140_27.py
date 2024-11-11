for i in range(int(input())):
    a=input()
    l=list(map(int,input().split()))
    l.sort()
    print(*l[::-1])