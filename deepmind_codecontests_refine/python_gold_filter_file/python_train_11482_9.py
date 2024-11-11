for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    st=[]
    p=[]
    for i in range(1,n):
        if a[0]!=a[i]:
            st.append([1,i+1])
        else:p.append([a[i],i+1])
    if len(st)==0:print("NO")
    else:
        for i in range(len(p)):
            st.append([st[0][1],p[i][1]])
        print("YES")
        for i in st:
            print(i[0],i[1])
