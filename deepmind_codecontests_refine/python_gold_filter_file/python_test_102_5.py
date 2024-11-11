import sys
#sys.setrecursionlimit(20000)
#from collections import deque #Counter
#from itertools import accumulate
#from functools import product
#import math


def rall():
    return sys.stdin.readlines()
def rl():
    return sys.stdin.readline().strip()
def rl_types(types):
    str_list = [x for x in sys.stdin.readline().strip().split(' ')]
    return [types[i](str_list[i]) for i in range(len(str_list))]

def pr( something='' ):
    sys.stdout.write( str(something) + '\n')
def pra( array ):
    sys.stdout.write( ' '.join([str(x) for x in array]) + '\n')


def solve(array):
    return array


if __name__ == '__main__':

    NT = int( rl() )
    #a,b = map(int,rl().split(' '))

    for ti in range(NT):
        n,m = map(int, rl().split(' '))
        commands = rl()

        start = [1,1]
        if n>1 or m>1:
            x,y = 0,0
            maxX,minX,maxY,minY = 0,0,0,0
            last_command = None
            for c in commands:

                #print('  ',x,y,c,end=' ')
                if c=='R':
                    x += 1
                    maxX = max(x,maxX)
                if c=='L':
                    x -= 1
                    minX = min(x,minX)
                if c=='U':
                    y -= 1
                    minY = min(y,minY)
                if c=='D':
                    y += 1
                    maxY = max(y,maxY)
                #print(x,y)
                #print(f'{c} minX={minX},maxX={maxX} minY={minY},maxY={maxY}')
                if maxX-minX==m:
                    #print('OFF!')
                    if c=='R':
                        maxX -= 1
                        x -= 1
                    if c=='L':
                        minX += 1
                        x += 1
                    break
                if maxY-minY==n:
                    #print('OFF!')
                    if c=='U':
                        minY += 1
                        y += 1
                    if c=='D':
                        maxY -= 1
                        y -= 1
                    break

            #print(last_command)

            #print(f'minX={minX},maxX={maxX} minY={minY},maxY={maxY}')
            #print(x,y)
            #yrng = [1+nU,n-nD]
            ##xrng = [1+nL,m-nR]
            #start[0] = yrng[1] if nU>nD else yrng[0]
            #start[1] = xrng[1] if nL>nR else xrng[0]
            #print(xrng,yrng)
            start = [1-minY,1-minX]



        # vals = rl_types( [str,float,float] )
        pra(start)

