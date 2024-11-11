for _ in range(int(input())):
    n=int(input())
    a=input()
    a+='0'
    b=input()
    b+='0'
    b=b[::-1]
    res=[]
    for i in range(n):
        if(a[i]!=a[i+1]):
            res.append(i+1)
    for j in range(n):
        if(b[j]!=b[j+1]):
            res.append(n-j)
    print(len(res),*res)