for t in range(int(input())):
    n=int(input())
    a=input()
    b=input()
    ans=[]
    for i in range(n):
        if(a[i]!=b[i]):
            ans.append(i+1)
            ans.append(1)
            ans.append(i+1)
    print(len(ans),*ans)