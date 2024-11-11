a,b = map(int,input().split())
if b==a:print(1)
elif b%10 == 0:print(0)
else:
    dif = b-a
    if (b%10 == 5 and dif>1) or (dif > 4):
        print(0)
    else:
        ans = 1
        while(b!=a):
            ans*=b
            b-=1
        print(ans%10)