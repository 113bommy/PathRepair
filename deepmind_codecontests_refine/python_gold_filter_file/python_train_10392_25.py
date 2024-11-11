# -*- coding: utf-8 -*-
def solve():
    N = int(input())
    Z = [tuple(map(int, input().split())) for _ in [None]*N]
    p = set(z%2 for z in map(sum,Z))
    if len(p) == 2:
        res = '-1'
    else:
        res = ''
        mode, *_ = p
        mode = 1-mode
        D = [2**i for i in range(30,-1,-1)]
        res += str(31+mode)
        res += '\n' + ' '.join(str(d) for d in D+[1]*mode)
        wdict = {(True, True):('R', (1,0)), (True, False):('U', (0,1)), (False, False):('L',(-1,0)), (False, True):('D',(0,-1))}
        for x, y in Z:
            x -= mode
            W = '\n'
            for d in D:
                w, (a, b) = wdict[x+y>0, x-y>0]
                W += w
                x -= a*d
                y -= b*d
            W += 'R'*mode
            res += W
    return str(res)

if __name__ == '__main__':
    print(solve())