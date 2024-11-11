def kwa():
    n, k = list(map(int, input().split()))
    l = list(map(int, list(input())))
    lst = []
    for i in range(n):
        if l[i] == 1: lst.append(i)
    res = [0 for x in range(len(lst))]
    for i in range(1, len(lst)):
        if lst[i]-lst[i-1] > k: return -1
    for i in range(len(lst)):
        j = i+1
        while j < len(lst) and lst[j]-lst[i] <= k:
            #res[j] += 1
            #new = res[i] + 1
            if res[j] > res[i]+1 or res[j] == 0: res[j] = res[i] + 1
            j += 1
    #print(lst)
    #print(res)
    if res[-1] == 0: return -1
    return res[-1]
    
print(kwa())