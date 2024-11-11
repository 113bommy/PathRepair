from sys import stdin as si
from collections import Counter as c


class Solution:

    def bazinga(self,n ,m):
        m[0]=1
        for i in range(1,n-1):
            m[i] = min(m[i - 1]+1, m[i], i + 1)
        m[n-1]=1
        for i in range(n - 2, -1, -1):
            m[i] = min(m[i], m[i + 1] +1)

        return(max(m))


if __name__ == '__main__':
    #for i in range(int(si.readline().strip())):
    n = int(si.readline().strip())
    #n,m = map(int, si.readline().strip().split())
    m = list(map(int, si.readline().strip().split()))
    S = Solution()
    print(S.bazinga(n,m))


'''
http://codeforces.com/contest/573/problem/B
'''