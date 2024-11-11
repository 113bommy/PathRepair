a,b,n=map(int,input().split())
for i in range(n+1):
    if (i+1)%2!=0:
        z=1
        c=1
        while(z<=a):
            if a%z==0 and n%z==0:
                c=z
            z+=1
        n=n-c
        if n<0:
            print('1')
            break
    else:
        z = 1
        c = 1
        while (z <= b):
            if b % z == 0 and n % z == 0:
                c = z
            z += 1
        n = n - c
        if n < 0:
            print('0')
            break
