N = int(input())
X = int(-(-N // 1.08))
print(X if int(X * 1.08) == N else ':(')
