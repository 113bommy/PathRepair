for _ in range(int(input())):
    n,a,b=map(int,input().split())
    c=a//b
    s=""
    d=1
    e=1
    k='a'
    for i in range(a):
        if d<=c:
            s+=k
            d+=1
        if e>=b:
            s+=k*(a-i-1)
            break
        if d>=c:
            d=1
            k=chr(ord(k)+1)
            e+=1
    h=n-a
    if h>a:
        s+=s*(h//a)
        s+=s[:h%a]
    else:
        s+=s[:h]
    print(s)