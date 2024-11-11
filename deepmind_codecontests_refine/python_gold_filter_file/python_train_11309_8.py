n=int(input());a=int(input());b=int(input())
p=max(a,b);q=min(a,b)
if p%q==0 and n%q!=0:
    print('NO')
else:
    if n%p==0:
        print('YES')
        ans1=int(n/p);ans2=0
        if a>b:
            print(ans1,ans2)
        else:
            print(ans2,ans1)
    else:
        xp=0
        while n>0:
            if n%q==0:
                print('YES')
                ans1=xp;ans2=int(n/q)
                break
            else:
                n-=p
                xp+=1
        if n<0:
            print('NO')
        else:
            if a>b:
                print(ans1,ans2)
            else:
                print(ans2,ans1)
        

