n=int(input())
if(n==1 or n==2):
    print(1)
else:
    if(n%3==0):
        print(2*(n//3))
    else:
        print(2*(n//3)+1)
