t = int(input())
for test_case in range(t):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input()))
    ones = [-k-1]
    more = 0
    for index, val in enumerate(arr):
        if val:
            ones.append(index)
        
    if len(ones)==1:
        more = (n+k)//(k+1)
    else:
        ones.append(n+k)
        for i in range(len(ones)-1):
            a, b = ones[i], ones[i+1]
            while b-a-1 >= 2*k+1:
                more += 1
                a += k+1
        
    print(more) 