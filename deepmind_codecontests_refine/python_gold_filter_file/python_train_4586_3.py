while True :
    num = 0
    n,x = map(int,input().split())
    if(n==0 and x==0): break
    for i in range (1,n) :
        for j in range(1,i):
            s = x - j - i
            if(s<=n and j<i and i<s):
                num += 1
    print(num)
