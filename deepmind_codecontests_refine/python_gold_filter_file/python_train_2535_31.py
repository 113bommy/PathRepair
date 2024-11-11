def Ele(n):
    if n == 1:
        print("1")
        return
    else:
        print(n,end=" ")
        for i in range(1,n):
            print(i,end=" ")
Ele(int(input()))