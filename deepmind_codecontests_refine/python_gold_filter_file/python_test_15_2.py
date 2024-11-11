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

    for _ in range(NT):
        n,m,k = map(int, rl().split(' '))
        grid = []
        for _ in range(n):
            row = [1 if c=='*' else 0 for c in rl()]
            grid.append(row)
        #grid = grid[::-1]

        needs = set()
        for r in range(n):
            for c in range(m):
                if grid[r][c]==1:
                    needs.add((r,c))

        len_neg  = [[x for x in row] for row in grid]
        len_pos  = [[x for x in row] for row in grid]
        min_tick  = [ [0]*m for _ in range(n)]

        can_cover = set()
        feasible = True
        for r in range(1,n):
            row = grid[r]
            for c in range(1,m-1):
                #print(r,c)
                if row[c] == 0:
                    pass
                else: # has 1
                    len_neg[r][c] = len_neg[r-1][c-1] + 1
                    len_pos[r][c] = len_pos[r-1][c+1] + 1
                    #min_tick[r][c] = min(len_neg[r][c],len_pos[r][c])
                    minsize = min(len_neg[r][c],len_pos[r][c])
                    if minsize > k:
                        min_tick[r][c] = minsize
                        # then can make tick of that size
                        can_cover.add( (r,c) )
                        for o in range(1,minsize):
                            if r-o >= 0:
                                if c-o >= 0:
                                    can_cover.add( (r-o,c-o) )
                                if c+o<m:
                                    can_cover.add( (r-o,c+o) )

        '''
        print('needs:',needs)
        print('can_cover:',can_cover)
        print('grid:')
        for row in len_neg:
            print('  ',row)
        print('len_neg:')
        for row in len_neg:
            print('  ',row)
        print('len_pos:')
        for row in len_pos:
            print('  ',row)
        print('min_tick:')
        for row in min_tick:
            print('  ',row)
        '''

        #print(needs-can_cover)
        print('YES' if len(needs-can_cover)==0 else 'NO')

