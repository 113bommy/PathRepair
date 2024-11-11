import sys
n = int(input())
sys.stdout.write(str(n))
for i in range(n+1, n*2):
    sys.stdout.write(" " + str(i))
