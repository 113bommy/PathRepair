n = int(input())

if n <3: print('No')

elif n % 4 ==0 or n%4==3:
    print('Yes')
    print("1 2")
    print(n-1),
    for i in range(1,n+1):
        if i==2:continue
        print(i),
else:
    sum = (n+1)*int(n/2)+n%2*int((n+1)/2)
    temp = -1
    for i in range(2,n+1):
        if (sum-i)%i==0:
            temp =i
            break
    if temp==-1:
        print('No')
    else:
        print('Yes')
        print('1 {}'.format(temp))
        print(n-1),
        for i in range(1,n+1):
            if i==temp:continue
            print(i),