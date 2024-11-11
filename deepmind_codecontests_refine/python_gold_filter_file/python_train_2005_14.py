t = int(input())

for _ in range(t):
    n= int(input())
    a= input()
    b=input()
    ans=[]
    c=0

    for i in range(n):
        if a[i]!=b[i]:
            ans+=[i+1,1,i+1]
    print(len(ans),*ans)