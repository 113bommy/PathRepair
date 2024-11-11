#import time
#begin = time.time()
arr100 = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199]
# This solution is The property OF no_soul
for _ in range(int(input())):
    n = int(input())
    adg = 1
    if n in arr100:
        lis = ['1'] * n
        for k in range(n):
            print(*lis)
            #xrfyvhibjxdtcghvjhbkj
    else:
        for kk in arr100:
            if kk > n:
                adg = kk - n
                #print(adg)
                if (adg + 1) not in arr100:
                    break
        for k in range(n):
            lis = ['1'] * n
            lis[k] = str(adg + 1)
            print(*lis)
#time.sleep(1)
#end = time.time()
#print(end-begin)