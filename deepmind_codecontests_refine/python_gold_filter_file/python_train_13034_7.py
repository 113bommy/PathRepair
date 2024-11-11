for _ in range(int(input())):
    n=int(input())
    li=list(map(int,input().split()))
    a=sum(li)
    b=0
    for i in li:
        b^=i
    if a==2*b:
        print(0)
        print('')
    else:
        ans=2
        if a%2==1:
            ans+=1
            a+=1
            b^=1
        print(ans)
        if ans==3:
            print(1,end=' ')
        if a>2*b:
            print(b,a+b)
        else:
            print(abs(a-2*b)//2,abs(a-2*b)//2)
        