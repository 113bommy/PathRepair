t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    if len(set(arr))==1:
        print(1)
        print('1 '*n)
    elif n%2==0:
        print(2)
        print('1 2 '*(n//2))
    else:
        a=arr[-2]
        b=arr[-1]
        c=arr[0]
        if a==b:
            print(2)
            print('1 2 '*(n//2)+'2')
        elif a!=b:
            if b==c:
                print(2)
                print('1 2 '*(n//2)+'1')
            else:
                i=0
                while i<n-1 and arr[i+1]!=arr[i]:
                    i+=1
                if i==n-1:
                    print(3)
                    print('1 2 '*(n//2)+'3')
                else:
                    print(2)
                    d=i//2
                    if i%2==0:
                        print('1 2 '*(d)+'1 1 '+'2 '+((n-i-3)//2)*'1 2 ')
                    else:
                        print('1 2 '*(d)+'1 2 2 '+'1 2 '*((n-i-2)//2))
