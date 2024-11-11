for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    if sorted(a)==a:
        print("0")
    else:
        i = n-1
        while(i > 0 and a[i-1]>=a[i]):
            i-=1
        while(i> 0 and a[i]>=a[i-1]):
            i-=1
        print(i)