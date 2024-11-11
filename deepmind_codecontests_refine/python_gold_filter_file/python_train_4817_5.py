for _ in range(int(input())):
    n = int(input())
    a = [*map(int,input().split())]
    p = max(a)
    s = sum(a)-p
    if((s+p)%2==1):
        print("T")
    elif(p>s):
        print("T")
    else:
         print("HL")