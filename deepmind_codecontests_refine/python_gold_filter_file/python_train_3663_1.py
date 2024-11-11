r = range(int(input()))
c = sorted(zip(map(int, input().split()), r))[::-1]
print(sum(c[i][0]*i+1 for i in r))
print(*(c[i][1]+1 for i in r))