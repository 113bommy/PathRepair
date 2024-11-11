for _ in range(int(input())):
    x = int(input())
    x1 = [int(i) for i in range(1,x+1) if i%2==0]
    x2 = [int(i) for i in range(1,x+1) if i%2!=0]
    print(*x1+x2,sep=" ")
