a=int(input())
b=int(input())
if a>b :
    j=a-b
else:
    j=b-a
if j%2==0 :
    k=j//2
    l=(k*(k+1))//2
    print(2*l)
else :
    k=j//2
    m=(k*(k+1))//2
    print(m*2+(j//2+1))
