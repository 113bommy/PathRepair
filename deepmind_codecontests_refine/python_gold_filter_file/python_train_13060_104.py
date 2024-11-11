import sys 
import queue

#file = open("in.txt", "r")

data = sys.stdin.read().split()

N = int(data[0])

def composite(n):
    if n == 1:
        return False

    for i in range(2, n-1):
        if n % i == 0:
            return True
        if i*i > n:
            break
    return False


for i in range(2, int(N / 2) + 1):
    j = N-i
    if composite(i) and composite(j):
        print(i, ' ', j)
        break

