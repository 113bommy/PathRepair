for _ in range(int(input())):
    n=int(input())
    if n<=3:
        print(-1);continue
    x=n-(n%2==0)
    an=[]
    while x>0:
        an.append(x);x-=2
    an.append(4);an.append(2)
    k=len(an);x=6
    while k<n:
        an.append(x);k+=1;x+=2
    print(*an)