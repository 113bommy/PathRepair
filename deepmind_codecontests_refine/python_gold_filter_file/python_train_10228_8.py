n=int(input())
for i in range(n):
    x=input().split()
    if((int(x[0])%2==int(x[1])%2) and (int(x[1])**2<=(int(x[0])))):
        print("YES")
    else:
        print("NO")
