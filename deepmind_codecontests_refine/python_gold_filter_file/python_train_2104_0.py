'''input
11
(R)R(R)Ra)c
'''

# MODIFIED SEGMENT TREE (MIN = MINIMUM PREFIX SUM instead of MINIMUM ELEMENT IN PREFIX)

class SegmentTree:
    def __init__(self, n, arr=[]):
        self.n = n
        self.tsum = [0] * (2 * n)
        self.tmin = [0] * (2 * n)
        self.tmax = [0] * (2 * n)
        if arr:
            for i in range(len(arr)):
                self.tsum[n + i] = arr[i];
            for i in range(len(arr) - 1, 0, -1) :
                self.tsum[i] = self.tsum[i << 1] + self.tsum[i << 1 | 1];

    def update(self, p, val):
        p += self.n;
        self.tsum[p] = val;
        self.tmin[p] = val;
        self.tmax[p] = val;

        i = p;
        while i > 1:
            self.tsum[i >> 1] = self.tsum[i] + self.tsum[i ^ 1];
            self.tmin[i >> 1] = min(self.tmin[i], self.tmin[i ^ 1] + self.tsum[i]) if i%2==0 else min(self.tmin[i^1], self.tmin[i] + self.tsum[i^1])
            self.tmax[i >> 1] = max(self.tmax[i], self.tmax[i ^ 1] + self.tsum[i]) if i%2==0 else max(self.tmax[i^1], self.tmax[i] + self.tsum[i^1])
            i >>= 1;

'''
import math
array = [1,3,5,7,9,11]
n = 2 ** math.ceil(math.log(len(array), 2))
st = SegmentTree(n, array)
st.update(0, 2)
'''

from sys import stdin
import math
def input():
    return stdin.readline()[:-1]

n = int(input())
s = input()

#n = 2 ** math.ceil(math.log(n, 2))
n = 1048576
st = SegmentTree(n)

maxit = -1
currentit = 0
output = []
for c in s:
    if c == 'L':
        currentit = max(0, currentit - 1)
    elif c == 'R':
        currentit += 1
    else:
        maxit = max(maxit, currentit)
        if c == '(':
            st.update(currentit, 1)
        elif c == ')':
            st.update(currentit, -1)
        else:
            st.update(currentit, 0)

    vmax = st.tmax[1]
    vmin = st.tmin[1]
    vsum = st.tsum[1]
    if vmin >= 0 and vsum == 0:
        output.append(vmax)
    else:
        output.append(-1)

print(' '.join(map(str, output)))

