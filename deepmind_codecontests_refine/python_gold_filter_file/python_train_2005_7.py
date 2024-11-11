
from sys import stdin
import sys
tt = int(input())

for loop in range(tt):

    n = int(input())

    a = input()
    b = input()

    if n == None:
        if a[0] == b[0]:
            print (0)
        else:
            print (1,1)
        sys.exit()

    ind = [None] * n
    tmp = 0
    for i in range(n-1,-1,-2):
        ind[i] = tmp
        tmp += 1
    if n % 2 == 0:
        for i in range(0,n,2):
            ind[i] = tmp
            tmp += 1
    else:
        for i in range(1,n,2):
            ind[i] = tmp
            tmp += 1

    #print (*ind)

    ans = []
    x = 0
    for i in range(n-1,-1,-1):

        if x == 0 and b[i] == a[ind[i]]:
            ans.append(1)
        elif x == 1 and b[i] != a[ind[i]]:
            ans.append(1)
        ans.append(i+1)
        x ^= 1

    print (len(ans),*ans)
