a=list(input())
for i in range(0,len(a)):
    a[i]=int(a[i])
if(len(a)==1):
    if(a[0]%8==0):
        print("YES")
        print(a[0])
        exit()
    else:
        print("NO")
        exit()
if(len(a)==2):
    if((a[1]*10+a[0])%8==0):
        print("YES")
        print(a)
    elif(a[0]%8==0):
        print("YES")
        print(a[0])
    elif(a[1]%8==0):
        print("YES")
        print(a[1])
    else:
        print("NO")
else:
    for i in range(len(a)-1,1,-1):
        for j in range(i-1,0,-1):
            for k in range(j-1,-1,-1):
                if((a[i]+a[j]*10+a[k]*100)%8==0):
                    print("YES")
                    for t in range(0,k+1):
                        print(a[t],end='')
                    print(a[j],end='')
                    print(a[i],end='')
                    exit()
    for i in range(len(a)-1,0,-1):
        for j in range(i-1,-1,-1):
            if((a[i]+a[j]*10)%8==0):
                print("YES")
                print(a[j]*10+a[i])
                exit()
    for i in range(len(a)-1,-1,-1):
        if(a[i]%8==0):
            print("YES")
            print(a[i],end='')
            exit()
    print("NO")