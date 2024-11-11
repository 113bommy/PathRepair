n = int(input())
w = list(map(int,input().split()))
fibArr = [0]

if(n==1):print(1)
elif(n==2):print(2)
else:
    #cnt = w[0]+w[1]
    fibo = 2
    k = 2 
    while(k!=n):
        #print(k,k-1,k-2)
        cnt=w[k-1]+w[k-2] 
        if(cnt == w[k]):
            fibo+=1
            k+=1
            if(fibo>fibArr[0]):
                fibArr[0] = fibo
        else:
            fibo = 2
            k+=1
            if(fibo>fibArr[0]):
                fibArr[0] = fibo
            if(k>n):break
    print(fibArr[0])    