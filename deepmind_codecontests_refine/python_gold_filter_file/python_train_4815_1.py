"""
#If FastIO not needed, used this and don't forget to strip
#import sys, math
#input = sys.stdin.readline
"""

import sys, os, gc
 
ii = 0
_inp = b''
def getchar():
    global ii, _inp
    if ii >= len(_inp):
        _inp = os.read(0, 50000)
        gc.collect()
        ii = 0
    if not _inp:
        return b' '[0]
    ii += 1
    return _inp[ii - 1]
 
def input():
    c = getchar()
    if c == b'-'[0]:
        x = 0
        sign = 1
    else:
        x = c - b'0'[0]
        sign = 0
    c = getchar()
    while c >= b'0'[0]:
        x = 10 * x + c - b'0'[0]
        c = getchar()
    if c == b'\r'[0]:
        getchar()
    return -x if sign else x



"""
1 2 3 4 5
1 2 3 4
2 3 4
2 3
3
"""

def solve():
    N = input()
    Q = input()
    binary_tree = [0]*(N+1)
    def update(index, value, bi_tree):
        """
        Updates the binary indexed tree with the given value
        :param index: index at which the update is to be made
        :param value: the new element at the index
        :param array: the input array
        :param bi_tree: the array representation of the binary indexed tree
        :return: void
        """
        while index < N+1:
            bi_tree[index] += value
            index += index & -index
    for i in range(N+Q):
        x = input()
        if x > 0:
            while x < N+1:
                binary_tree[x] += 1
                x += x & -x
        else:
            idx = 0
            K = -x-1
            L = len(bin(N))-2
            for j in range(L-1,-1,-1):
                R = idx + pow(2,j)
                if R < N+1 and K >= binary_tree[R]:
                    idx = R
                    K -= binary_tree[idx]
            idx += 1
            while idx < N+1:
                binary_tree[idx] -= 1
                idx += idx & -idx
        #print(binary_tree)
    for i in range(1,N+1):
        if binary_tree[i] > 0:
            return i
    return 0
    
    
#for _ in range(getInt()):
print(solve())
    #solve()