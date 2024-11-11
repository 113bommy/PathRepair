t=int(input())
for _ in range(t):
    n=int(input())
    c=0
    a=2
    temp=n
    while(temp>0 and a<=7):
        c+=temp//a
        temp%=a
        a+=1
    print(c)