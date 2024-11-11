t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))[:n]
    for i in range(n):
        if a[i]%2==0:
            print("1")
            print(i+1)
            break
        else:
            if n==1:
                print("-1")
                break
            else:
                k=a[i]+a[i+1]
                if k%2==0:
                    print("2")
                    print(i+1,i+2)
                    break

