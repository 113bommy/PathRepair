n=int(input())
if n==1:
    print('I hate it')
elif n==2:
    print('I hate that I love it')
elif n%2==0:
    for i in range(n//2-1):
        print('I hate that I love that',end=' ')
    print('I hate that I love it')
else:
    for i in range(n//2):
        print('I hate that I love that',end=' ')
    print('I hate it')
