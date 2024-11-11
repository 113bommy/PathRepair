import random
import sys
import os

n = int (input())
s = set (map(int , input().split()))
s = sorted (s)
for i in range(0 , len(s) - 2) :
    #print (i + 2)
    if s[i + 2] - s[i] == 2:
        print ('YES')
        exit ()
print ('NO')

'''
t = int(input ())
while (t > 0):
    read=lambda:map(int,input().split())
    n,m,k=read()
    ind=list(map(int,input().split()))
    ans = 0
    for d in range (0 , k):
        ind[d] = ind[d] - 1
        i = ind[d] // m
        j = ind[d] % m
        #print (i , j)
        ans = ans + (n - i) * (m - j) * (i + 1) * (j + 1)
    print("%.10f" % (4 * ans / (n * m * (n + 1) * (m + 1))))
    t = t - 1
'''