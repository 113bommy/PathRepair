n = int(input())
for i in range(0,n):
    temp = map(int,input().split())
    a,b = temp
    if a == b:
        if b%2==0:
            t = b
        else:
            t = b*(-1)
    else:
        if a%2==0:
            if b%2==0:
                t = a + (b-a)/2
            else:
                t = (((b-a)+1)/2)*(-1)
        else:
            if b%2==0:
                t = ((b-a)+1)/2
            else:
                t = (b-a)/2 - b
    print(int(t))
