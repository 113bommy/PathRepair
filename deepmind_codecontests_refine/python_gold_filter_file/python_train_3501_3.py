n,m = map(int, input().split())
s = input()
list = list(s)
for i in range(m):
    l,r,c1,c2 = map(str, input().split())
    l = int(l)
    r = int(r)
    for j in range(l,r+1):
        if(list[j-1] == c1):
            list[j-1] = c2
print(''.join(list))