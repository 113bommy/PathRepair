a=[]
for ctr in range(int(input())):
    x,y=map(int,input().split())
    a.append([x,y])
for i in range(len(a)):
    for j in range(i+1,len(a)):
        xi=a[i][0]
        xj=a[j][0]
        di=a[i][1]
        dj=a[j][1]
        if xi+di == xj and xj+dj == xi:
            print("YES")
            exit()
print("NO")
