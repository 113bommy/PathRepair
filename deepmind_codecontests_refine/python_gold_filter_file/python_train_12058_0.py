N = int(input())
W = [input() for i in range(N)]
if all(W[i][0]==W[i-1][-1] and W[i] not in W[:i] for i in range(1, N)):
    print('Yes')
else:
    print('No')
