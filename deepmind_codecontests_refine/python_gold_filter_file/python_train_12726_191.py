# -*- coding: utf-8 -*-
"""
Created on Thu May 14 11:12:04 2020

@author: Tofu
"""

# -*- coding: utf-8 -*-
"""
Created on Thu May 14 10:38:20 2020

@author: Tofu
"""

def Most_unstable(n,m):
    #print(n,m)
    if n == 1:
        return 0
    elif n-2 > 0:
        return m*2
    else:
        return m


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        line = input().rstrip().split()
        #print(line)
        n = int(line[0])
        m = int(line[1])
    
        ans = Most_unstable(n,m)
        print(ans)
        print('\n')