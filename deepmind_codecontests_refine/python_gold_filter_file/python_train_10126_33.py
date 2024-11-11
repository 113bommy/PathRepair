t=int(input())
for i in range(t):
    c={}
    n=int(input())
    for j in range(n):
        s=input()
        for x in s:
            if(x in c):
                c[x]+=1
                if(c[x]==n):
                    del c[x]
            else:
                c[x]=1
    if(len(c)==0 or n==1):
        print("YES")
    else:
        print('NO')
