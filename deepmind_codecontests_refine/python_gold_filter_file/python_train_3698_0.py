'''
Author : Md. Rezwanul Haque
Email : r.haque.249.rh@gmail.com
'''

import sys
from sys import stdout,stdin
input = lambda : sys.stdin.readline()

if __name__ == '__main__':
    n = int(input())
    s = input()
    s = (s.count('B'), s.count('G'), s.count('R'))

    if s[0] > 0 and s[1] > 0 and s[2] > 0:
        stdout.write("BGR")
    elif s[0] == 0 and s[1] == 0:
        stdout.write("R")
    elif s[1] == 0 and s[2] == 0:
        stdout.write("B")
    elif s[0] == 0 and s[2] == 0:
        stdout.write("G")

    elif s == (0,1,1):
        stdout.write("B")
    elif s == (1, 0, 1):
        stdout.write("G")
    elif s == (1, 1, 0):
        stdout.write("R")

    elif s[0] == 0 and s[1] == 1:
        stdout.write("BG")
    elif s[0] == 0 and s[2] == 1:
        stdout.write("BR")
    elif s[1] == 0 and s[0] == 1:
        stdout.write("BG")
    elif s[1] == 0 and s[2] == 1:
        stdout.write("GR")
    elif s[2] == 0 and s[0] == 1:
        stdout.write("BR")
    elif s[2] == 0 and s[1] == 1:
        stdout.write("GR")
    else:
        stdout.write("BGR")