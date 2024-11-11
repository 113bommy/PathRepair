import random
import math
from collections import defaultdict
import itertools
from sys import stdin, stdout
import sys
import operator
from decimal import Decimal

# sys.setrecursionlimit(10**6)

p2D = lambda x: print(*x, sep="\n")


def II(): return int(sys.stdin.buffer.readline())


def MI(): return map(int, sys.stdin.buffer.readline().split())


def LI(): return list(map(int, sys.stdin.buffer.readline().split()))


def LLI(rows_number): return [LI() for _ in range(rows_number)]


def BI(): return sys.stdin.buffer.readline().rstrip()


def SI(): return sys.stdin.buffer.readline().rstrip().decode()


def main():
    # z = ''
    # p = lambda *a: print(*a, flush = True)
    # d = defaultdict()

    #mod = 10 ** 9 + 7
    for _ in range(int(input())):
        #n = int(input())
        n, m = [int(i) for i in input().split()]
        #s = input()
        a = list(map(int, input().split()))
        # s = SI()
        # c = LI()
        b = list(set(a))
        p = len(b)
        if p > m:
            print(-1)
        else:
            if p<m:
                for i in range(1,n+1):
                    if i not in b:
                        b.append(i)
                        p+=1
                    if p == m:
                        break

            b.sort()

            tmp = ''
            for bi in b:
                tmp+= str(bi)+ ' '

            ans = ''

            for _ in range(len(a)):
                ans+= tmp

            print(len(b)*n)
            print(ans)



#        print(b)



    # s = input()

    #    s = input()

    #     z += str(ans) + '\n'
    # print(len(ans), ' '.join(map(str, ans)), sep='\n')
    # stdout.write(z)


# for interactive problems
# print("? {} {}".format(l,m), flush=True)
# or print this after each print statement
# sys.stdout.flush()


if __name__ == "__main__":
    main()