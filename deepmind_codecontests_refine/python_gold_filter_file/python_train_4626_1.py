#import math
N = int(input())
#n, m = input().split()
#n = int (n)
#m = int (m)
#n, m, k= input().split()
#n = int (n)
#m = int (m)
#k = int (k)
#l = int(l)
#m = int(input())
#s = input()
##t = input()
#a = list(map(char, input().split()))
#a.append('.')
#print(l)
#a = list(map(int, input().split()))
#c = sorted(c)
#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
#f = []
#t = [0]*n
#f = [(int(s1[0]),s1[1]), (int(s2[0]),s2[1]), (int(s3[0]), s3[1])]
#f1 = sorted(t, key = lambda tup: tup[0]
rope = []
for i in range(100):
    rope.append('n')
n, m = input().split()
n = int (n)
m = int (m)
for i in range(n,m):
    rope[i] = 'y'
for i in range (N-1):
    n, m = input().split()
    n = int (n)
    m = int (m)
    for i in range(n,m):
        rope[i] = 'n'
print(rope.count('y'))
