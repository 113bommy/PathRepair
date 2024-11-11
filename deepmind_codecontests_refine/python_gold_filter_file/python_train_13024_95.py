s=input().rstrip().split(' ')
a=int(s[0])
b=int(s[1])
if b<=a:
    print(1)
elif b%a==0:
    print(b//a)
else:
    O=0;
    while(1):
        t=b//a;
        v=b%a;
        O+=t;
        b=v;
        if (t+v)<=a:
            O+=1;
            break;
    print(O)
