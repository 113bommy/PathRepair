n, m = map(int, input().split())
s = list(input())
lst = [[i for i in input().split()] for i in range(m)]
for i in range(m):
    l = int(lst[i][0])
    r = int(lst[i][1])
    c1 = lst[i][2]
    c2 = lst[i][3]
    for j in range(l-1,r):
        if s[j]==c1:
            s[j] = c2
print(''.join(s))
