'''
Created on Jan 27, 2015

@author: mohamed265
'''
t = input().split()
n = int(t[0])
m = int(t[1]) 
print(n + m - 1)
for i in range(m):
    print(1, i + 1)
for i in range(1, n):
    print(i + 1, 1)

