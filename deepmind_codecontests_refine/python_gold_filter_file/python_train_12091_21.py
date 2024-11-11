'''input
3 1000000000 1
1000000000 987654321 1000000000
'''
from sys import stdin




# main starts
n, m, k = list(map(int, stdin.readline().split()))
arr = list(map(int, stdin.readline().split()))
arr.sort()
a = m // (k + 1)
maxhappy = (arr[-1]* k + arr[-2]) * a
maxhappy += (arr[-1]) *( m % (k + 1))
print(maxhappy)