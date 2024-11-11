#import math
#n, m = input().split()
#n = int (n)
#m = int (m)
#k = int (k)
n = int(input())
#m = int(input())
#s = input()
#t = input()
#h = list(map(int, input().split()))
#b = list(map(int, input().split()))
#c = list(map(int, input().split()))

#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
#f = []
#f = [0]*n
#t = [0]*n
#f = [(int(s1[0]),s1[1]), (int(s2[0]),s2[1]), (int(s3[0]), s3[1])]
#f = sorted (f, key = lambda tup: tup[0] )

#h = [""] * n
#f1 = sorted(f, key = lambda tup: tup[0])


#f1 = sorted(t, key = lambda tup: tup[0])


c = 18
for i in range (1, 17):
    m = n+i
    m = abs(m)
    while (m > 0):
        k = m % 10
        if (k == 8):
            c = min (c, i)
            break
        m //= 10
print (c)
