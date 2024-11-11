for t in range(int(input())):
    #n=int(input())
    r,c=map(int,input().split())
    f=[3]+[4]*(c-2)+[3]
    e=[2]+[3]*(c-2)+[2]
    b=[]
    flag=0
    for i in range(r):          
        a=list(map(int,input().split()))
        b.append(a) 
        if i==0 or i==r-1:
            if a[-1]>2 or max(a)>3 or a[0]>2 :
                flag=1
        else:
            if a[0]>3 or max(a)>4 or a[-1]>3 :
                flag=1
    if flag!=1:
        print("YES")
        if(r!=2):
            print(*e)
            for i in range(r-2):
                print(*f)
            print(*e)
        else:
            print(*e)
            print(*e)
    else:
        print("NO")
    