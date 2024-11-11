
import math

for test in range(int(input())):
    n = int(input())
    a = [*map(int,input().split())]

    c = []
    max_num = max(a)
    max_idx = a.index(max_num)
    c.append(max_num)
    a.pop(max_idx)

    gcd_1 = False
    curr_gcd = c[0]
    for i in range(n-1):
        #print(a)
        val = math.gcd(a[0],curr_gcd)
        h_idx = 0
        if gcd_1 is False:
            for idx,j in enumerate(a):
                value = math.gcd(j,curr_gcd)
                if value > val:
                    val = value
                    h_idx = idx
                        
        curr_gcd = val
        if val == 1:
            gcd_1 = True
        if gcd_1 is True:
            max_num = max(a)
            max_idx = a.index(max_num)
            c.append(max_num)
            a.pop(max_idx)
        else:
            c.append(a[h_idx])
            a.pop(h_idx)
    for i in c:
        print(i, end = ' ')
    print()


    

    









