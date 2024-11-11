n=int(input())
i,j=0,0
while i*1234567<=n:
    while i*1234567+j*123456<=n:
        if (n-i*1234567-j*123456)%1234==0:
            print("YES")
            exit()
        j+=1
    j=0
    i+=1
print("NO")