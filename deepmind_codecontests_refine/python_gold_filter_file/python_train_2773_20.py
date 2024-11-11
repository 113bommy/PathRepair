n=int(input())
h,m = [int(i) for i in input().split()]

if h%10==7 or m%10==7 or h//10==7 or m//10==7 :
    print(0)
else :
    c = 0
    while True:
        m-=n
        c+=1
        if m<0:
            m+=60
            h-=1
            if h<0 :  h=23
        if h%10==7 or m%10==7 or h//10==7 or m//10==7 :
            print(c)
            break;
