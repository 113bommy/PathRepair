from math import *
import sys, random
def nextInt():
	return int(input())
def nextStrs():
	return input().split()
def nextInts():
	return list(map(int,nextStrs()))



def main():
    t = nextInt()

    while t > 0:
        a = nextInts()

        a.sort()

        print(a[1]+a[2])
        t-=1

if __name__ == '__main__':
    exit(main())