a,b = map(int,input().split())
if b>=(a*(a-1))//2:
    print("no solution")
else:
    pos = 2
    for i in range(a-1):
        print(1,pos)
        pos+=8
    print(1,pos-7)