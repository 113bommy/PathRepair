import sys 
n = int(input())
a = [int(s) for s in input().split()]
for i in range(0,2):
    for j in range(i+1,n):
        if a[i] != a[j]:
            r = a[j]
            a[j] = a[i]
            a[i] = r
            lol = True
            lol1 = True
            for h in range(1,n):
                if a[h-1] > a[h]:
                    lol = False
                if a[h-1] < a[h]:
                    lol1 = False
            if not(lol) and not(lol1):
                print(i+1,j+1)
                sys.exit()
            else:
                r = a[j]
                a[j] = a[i]
                a[i] = r
print(-1)
