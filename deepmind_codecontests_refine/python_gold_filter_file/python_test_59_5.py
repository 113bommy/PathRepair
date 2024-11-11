T=int(input())
for _ in range(T):
    n=int(input())
    students=[]
    for _ in range(n):
        s=list(map(int,input().split(' ')))
        students.append(s)
    days=[0,0,0,0,0]
    for s in students:
        for x in range(5):
            days[x]+=s[x]
    def check(d1,d2):
        n1=0
        n2=0
        n12=0
        for s in students:
            if s[d1]and s[d2]:
                n12+=1
            elif s[d1]:
                n1+=1
            elif s[d2]:
                n2+=1
            else:
                return False
        # print(n1,n2,n12,'asddsa')
        if n12+n1+n2!=n:
            return False
        if max(n1,n2)-min(n1,n2)>n12:
            return False
        n12-=max(n1,n2)-min(n1,n2)
        if n12%2:
            return False
        # if (max(n1,n2)+n12//2)%2:
        #     return False
        return True


    res=False
    while 1:
        # print(days)
        if res:
            break
        top=max(days)
        topD=days.index(top)
        days[topD]=0
        if top<n//2:
            res=False
            break 
        for d_i in range(5):
            d=days[d_i]   
            if d<n//2:
                days[d_i]=0
            else:
                # print(topD,d_i)
                if check(topD,d_i):
                    res=True
                    break


    if res:
        print('YES')
    else:
        print('NO')