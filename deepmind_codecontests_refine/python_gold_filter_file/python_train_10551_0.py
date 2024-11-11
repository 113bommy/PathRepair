'''input
2 3 4
'''
a, b, c = sorted(map(int, input().split()))
print((b+a-1)*(c+a-1) - a*(a-1))

