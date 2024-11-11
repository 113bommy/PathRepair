n = int(input())
pairs = []
L = 0
R = 0
for i in range(n):
    pair = input().split(' ')
    L += int(pair[0])
    R += int(pair[1])
    pairs.append((int(pair[0]), int(pair[1]), (i+1)))
pairs.sort(key = lambda x: abs(L - R + 2*(x[1] - x[0])))
if abs(L - R + 2*(pairs[-1][1] - pairs[-1][0])) <= abs(L - R):
    print(0)
else:
    print(pairs[-1][2])
