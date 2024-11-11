for x in range(int(input())):
    n = int(input())
    m=list(map(int,input().split()))
    r='YES'
    if n<10:
        r='NO'
    else:
        k=2
        for i in range(n//2-1,2,-1):
            if m[i]>m[i+1]:
                k=i
                break
                
                
        a=[]
        p=0
        for i in range(n//2):
            if len(a)==0:
                if m[i]>m[i+1]:
                    a.append(i+1)
            else:
                p+=1
                if m[i]>m[i+1] and p>a[0]:
                    a.append(p)
                    if k-i>a[0]:
                        a.append(k-i)
                    break
        if len(a)<3:
            r='NO'
    if r=='YES':
        print(*a)
    else:
        print(0,0,0)

                