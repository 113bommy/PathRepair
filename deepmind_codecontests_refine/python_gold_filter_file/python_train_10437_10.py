#872
for _ in range(int(input())):
    n=int(input())
    a=[int(x)for x in input().split()]
    for i in range(n):
        if(i%2):
            print(abs(a[i]),end=" ")
        else:
            print(-abs(a[i]),end=" ")
    print()