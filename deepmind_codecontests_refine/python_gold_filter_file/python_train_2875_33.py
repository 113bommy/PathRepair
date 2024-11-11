from sys import stdin, stdout

n,k = map(int,stdin.readline().rstrip().split())

minH = min([1,k,n-k])
maxH = min([2*k,n-k])

print(str(minH) + ' ' + str(maxH))
