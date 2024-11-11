import sys
import math
# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

def C(n, k):
    if n < k:
        return 0
    return math.factorial(n) // math.factorial(k) // math.factorial(n - k);

def main():
    n = int(input())
    print(C(n, 5)**2 * 120)

main()