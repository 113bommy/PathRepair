n=int(input())
a=1
b=n-1
x=1
while x==1:
    a+=1
    b-=1
    for i in range(2,a):
        for j in range(2,min(b,50)):
            if a%i==0 and b%j==0:
                print(a,b)
                quit()