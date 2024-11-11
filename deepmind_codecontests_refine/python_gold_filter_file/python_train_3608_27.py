from sys import stdin

n = int(stdin.readline())

a = [int(x) for x in input().split(' ')]

t = []
p = 0

for i in range(len(a)):
    p += a[i]
    t.append(p)

for i in range(len(t)):
    if t[i] >= t[-1]/2:
        print(i+1)
        break


    
