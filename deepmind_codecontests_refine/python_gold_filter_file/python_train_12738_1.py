n=int(input())
if n%2==1:
    print("-1")
else:
    for i in range(n):
        if i%2==0:
            print(i+2,end=" ")
        else:
            print(i,end=" ")