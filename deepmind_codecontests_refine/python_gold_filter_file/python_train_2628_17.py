t=int(input())
for _ in range (t):
    n,m = map(int,input().split(' '))
    if(n==1 or m==1):
        print("YES")
        continue
    elif(n==2 and m==2):
        print("YES")
        continue
    else:
        print("NO")
        continue
