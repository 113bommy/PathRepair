for i in range(int(input())):
    a, b = map(int,input().split())
    print(min((b*2),((a-1)*b)))