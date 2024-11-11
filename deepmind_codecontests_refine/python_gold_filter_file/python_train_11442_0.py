while 1:
    n=int(input())
    if n==0:break
    a=0;i=1;b=n//2
    while i*i<b:a+=((b-1)//i+1)-i-1;i+=1
    a=(a+b-1)*2+i
    print(8*(a+n))