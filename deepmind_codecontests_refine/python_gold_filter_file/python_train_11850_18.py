n,m=map(int, input().split())
a=1
b=0
while b==0:
    for i in range(int(m**0.5)*10,1,-1):
        if m%i==0 and m>=(i*n):
            a*=i
            m=m//i
            break
    else:b=1
print(a)