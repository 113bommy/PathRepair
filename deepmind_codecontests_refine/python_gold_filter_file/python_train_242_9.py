n=int(input())
a={1:1,2:2,3:6,4:12,5:60,6:60}
if n in a:
    print(a[n])
else:
    if n%2!=0:
        print(n*(n-1)*(n-2))
    else:
        if n%3!=0:
            print(n * (n - 1) * (n - 3))
        else:
            print((n-3) * (n - 1) * (n - 2))