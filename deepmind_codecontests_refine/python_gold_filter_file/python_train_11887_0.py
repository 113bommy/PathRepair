n = int(input())
if(n%2==0): print("NO")
else:
    print("YES")
    i = 1
    while(i<2*n):
        print(i,end=" ")
        if(i%2==0): i+=1
        else: i+=3
    i = 2
    while(i<=2*n):
        print(i,end=" ")
        if(i%2==0): i+=1
        else: i+=3
    