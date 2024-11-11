test = int(input())
test_arr = []
for _ in range(test):
    a,b,n = map(int,input().split())
    m = max(a,b)
    if m<=n:
        start = a+b
        count = 1
        while(start<=n):
            i = max(start,m)
            start+=m
            m = i
            count+=1
    else:
        count = 0
    test_arr.append(count)
for t in test_arr:
    print(t)