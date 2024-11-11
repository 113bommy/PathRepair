n=int(input())
for i in range(n):
    out=0
    a,b=map(int,input().split())
    if b>a:
        a,b=b,a
    if a==b:
        print(0)
        continue
    while True:
        befa=a
        if a%2==0:
            a//=2
            if a==b:
                out+=1
                print(out)
                break
        a=befa
        if a%4==0:
            a//=4
            if a==b:
                out+=1
                print(out)
                break
        a=befa
        if a%8==0:
            a//=8
            out+=1
            if a==b:
                print(out)
                break
        else:
            print(-1)
            break
