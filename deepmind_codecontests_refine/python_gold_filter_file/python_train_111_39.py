n=int(input())
lst=[int(i) for i in input().split()]
sum1=0
sum2=0
max1=max(lst)
for i in lst:
    sum1=sum1+i
    sum2=sum2+max1-i
if sum1<sum2:
    print(max1)
else:
    d=sum1-sum2
    r=(d+1)%n
    if d==0:
        print(max1+1)
    elif r==0:
        print(max1+(d+1)//n)
    else:
        print(max1+((d+1)//n)+1)
