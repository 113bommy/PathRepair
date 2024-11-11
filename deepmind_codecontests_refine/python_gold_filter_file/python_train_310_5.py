import sys
input()
print(sum(1 for x in map(int,sys.stdin)if 2 in[x,pow(2,x,x)]))
