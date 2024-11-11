for i in range(int(input())):
    n2=n3=0
    num = int(input())
    while num % 2 == 0:
        n2+=1
        num/=2
    while num % 3 == 0:
        n3+=1
        num/=3
    print((2*n3-n2+1)*(num==1)*(n2<=n3)-1)