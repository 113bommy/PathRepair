n=int(input())
a=int(input())
b=int(input())
if(n//a<n//b):
    k=a
    m=b
else:
    k=b
    m=a
flag=0
if(n//k>0):
    for i in range(0,n//k+1):
        if((n-i*k)%m==0):
            flag=1
            print('YES')
            if(k==a):
                print (i,end=" ")
                print ((n-i*k)//m)
            elif(k==b):
                print ((n-i*k)//m,end=" ")
                print(i)
            break
    if(flag==0):
        print ("NO")
else:
    if(n%m==0):
        print ("YES")
        if(k==a):
            print (0,end=" ")
            print(n//m)
        else:
            print (n//m,end=" ")
            print (0)
    else:
        print ("NO")