#import math
#n, m = input().split()
#n = int (n)
#m = int (m)
#n, m, k = input().split()
#n = int (n)
#m = int (m)
#k = int (k)
n = int(input())
#m = int(input())
#s = input()
##t = input()
#a = list(map(int, input().split()))
#print(l)
#c = list(map(int, input().split()))

#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
#f = []
#t = [0]*n
#f = [(int(s1[0]),s1[1]), (int(s2[0]),s2[1]), (int(s3[0]), s3[1])]

#h = [""] * n
#f1 = sorted(f, key = lambda tup: tup[0])
u = 10**9+1
l = -u
for i in range(n):
    s = input().split()
    if (s[0] =='>='):
        if(s[2] == 'Y'):
            l = max(l, int(s[1]))
        else:
            u = min(u, int(s[1])-1)
    if (s[0] =='>'):
        if(s[2] == 'Y'):
            l = max(l, int(s[1])+1)
        else:
            u = min(u, int(s[1]))
    if (s[0] =='<='):
        if(s[2] == 'N'):
            l = max(l, int(s[1])+1)
        else:
            u = min(u, int(s[1]))
    if (s[0] =='<'):
        if(s[2] == 'N'):
            l = max(l, int(s[1]))
        else:
            u = min(u, int(s[1])-1)

if (l > u):
    print("Impossible")
else:
    print(u)
#f1 = sorted(t, key = lambda tup: tup[0])
