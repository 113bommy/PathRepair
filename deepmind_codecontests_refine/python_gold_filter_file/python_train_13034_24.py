# lET's tRy ThIS...

import math
import os
import sys

#-------------------BOLT------------------#
#-------Genius----Billionare----Playboy----Philanthropist----NOT ME:D----#

input = lambda: sys.stdin.readline().strip("\r\n")
def cin(): return sys.stdin.readline().strip("\r\n")
def fora(): return list(map(int, sys.stdin.readline().strip().split()))
def string(): return sys.stdin.readline().strip()
def cout(ans): sys.stdout.write(str(ans))
def endl(): sys.stdout.write(str("\n"))
def ende(): sys.stdout.write(str(" "))

#---------ND-I-AM-IRON-MAN------------------#


def main():
    for _ in range(int(input())):
        #LET's sPill the BEANS
        n=int(cin())
        a=fora()
        sumt=x=0
        for i in a:
            x^=i
            sumt+=i
        if(sumt==2*x):
            cout(0)
        else:
            cout(2)
            endl()
            cout(x)
            ende()
            cout(sumt+x)
        #print(sumt,x)
        endl()

if __name__ == "__main__": 
    main()
