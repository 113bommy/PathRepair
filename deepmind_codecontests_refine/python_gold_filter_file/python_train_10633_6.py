n,m=map(int,input().split())
a=[]
b=[]
for i in range(n):
    c=list(map(int,input().split()))
    a.append(c)
for i in range(n):
    c=list(map(int,input().split()))
    b.append(c)

for i in range(n):
    for j in range(m):
        if a[i][j]==b[i][j]:
            continue
        else:
            k=i+1;l=j-1
            flag=0
            while k<n and 0<=l:
                
                if a[k][l]==b[i][j]:
                    flag=1
                    a[i][j],a[k][l]=a[k][l],a[i][j]
                    break
                l-=1;k+=1
            if flag==0:
                print("NO")
                exit()
print("YES")