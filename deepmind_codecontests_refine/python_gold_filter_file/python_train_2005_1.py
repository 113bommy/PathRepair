t=int(input())
for i in range(t):
    n=int(input())
    a=input()
    b=input()
    ans=[]
    for i in range(len(a)):
        if a[i]!=b[i]:
            ans.append(i+1)
            ans.append(1)
            ans.append(i+1)
    print(len(ans),*ans,sep=" ")