for _ in range(int(input())):
    a,b,c=map(int,input().split())
    mid=(a+b)/2
    if c==a:
        print(1)
    elif c<=mid:
        print(2)
    elif c>=(mid+(a-b)/6) and c<a:
        d=(mid+(a-b)/6)
        if abs(d-c)<abs(a-c):
            print(3)
        else:
            print(1)
    else:
        c-=mid
        d=[]
        x=(a-b)//c
        if x%2==0:
            xx=x//2
            if xx%2==0:
                h=max(6,x-2)
                i=max(6,h-4)
                j=max(6,h+4)
            else:
                h=max(6,x)
                i=max(6,h-4)
                j=max(6,h+4)
            e=[abs(((a-b)/h)-c),h]
            f=[abs(((a-b)/i)-c),i]
            g=[abs(((a-b)/j)-c),j]
            d.append(e)
            d.append(f)
            d.append(g)
            d.sort()
            print(int(d[0][1]//2))
        else:
            xx=(x+1)//2
            if xx%2==0:
                h=max(6,x-1)
                i=max(6,h+4)
            else:
                h=max(6,x-3)
                i=max(6,h+4)
            e=[abs(((a-b)/h)-c),h]
            f=[abs(((a-b)/i)-c),i]
            d.append(e)
            d.append(f)
            d.sort()
            print(int(d[0][1]//2))