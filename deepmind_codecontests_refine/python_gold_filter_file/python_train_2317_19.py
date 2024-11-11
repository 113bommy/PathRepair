for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    odd = []
    even = []
    for i in range(len(a)):
        if a[i] % 2:
            odd.append(i)
        else:
            even.append(i)
    j = 0
    res = []
    while j+1<len(odd):
        res.append([odd[j], odd[j+1]])
        j += 2
    j = 0
    while j+1<len(even):
        res.append([even[j], even[j+1]])
        j += 2
    x = 1
    while x < n:
        print(res[x-1][0]+1, res[x-1][1]+1)
        x += 1


