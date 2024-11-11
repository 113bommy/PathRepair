for _ in range(1):
    n=int(input())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    l=[0]*n
    for i in range(n):
        l[i]=n-l1[i]-l2[i]
    for i in range(n):
        cl=0
        cr=0
        for j in range(i):
            if l[j]>l[i]:
                cl+=1
        for k in range(i+1,n):
            if l[k]>l[i]:
                cr+=1
        if cl!=l1[i] or cr!=l2[i]:
            print("NO")
            exit()
    print("YES")
    print(*l)
    