t = int(input())
s = [int(x)for x in input().split()]
tmp = []
for i in range(t):
    for ii in s:
        if (i+1) == ii:
            print(s.index(ii)+1, end=" ")
