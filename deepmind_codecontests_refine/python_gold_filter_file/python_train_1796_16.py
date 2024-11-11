for i in range(int(input())):
    n,k=[int(i) for i in input().split()]
    if n>=k:
        if k==1:
            print("Yes")
            print(n)
        elif k==n:
            print("Yes")
            print(" ".join(["1" for i in range(k)]))
        else:
            if (n-k+1)%2:
                print("Yes")
                print(" ".join(["1" for i in range(k-1)]),(n-k+1))
            else:
                if ((n-2*k+2)%2)==0 and ((n-2*k+2)>1):
                    print("yes")
                    print(" ".join(["2" for i in range(k-1)]),(n-2*k+2))
                else:
                    print("No")
    else:
        print("No")
