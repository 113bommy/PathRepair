for i in range(int(input())):
    n, k = map(int, input().split())
    t = n // k
    l = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
         'w', 'x', 'y', 'z']
    s = ""
    v = ""
    flag = 0
    if n%k!=0:
        flag = 1
    for jj in range(k):
        if flag ==0:
            s = s + l[jj] * t
        else:
            s = s+ l[jj]*t
            if jj==(k-1):
                s = s + l[jj]*(n%k)
    print(s)
