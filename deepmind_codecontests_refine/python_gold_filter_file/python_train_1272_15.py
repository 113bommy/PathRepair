"""
NTC here
"""
import sys
inp= sys.stdin.readline
input = lambda : inp().strip()
flush= sys.stdout.flush
# import threading
# setrecursionlimit(10**6)
# threading.stack_size(2**26)

def iin(): return int(input())
def lin(): return list(map(int, input().split()))

# range = xrange
# input = raw_input

def main():
    n = iin()
    a = lin()
    ch = [0]*35
    for i in a:
        ch1 = 0
        x = i
        while x:
            if x%2:
                ch[ch1]+=1
            x//=2 
            ch1+=1
    sl = [0]*n
    for i in range(n):
        ch1 = 0
        x = a[i]
        while x:
            if x%2:
                if ch[ch1]==1:
                    sl[i]+=2**ch1
            x //= 2
            ch1+=1
    sl = [[sl[i], i] for i in range(n)]
    sl.sort(reverse=True)
    ans = [a[j] for i,j in sl]
    print(*ans)










        
main()
#threading.Thread(target=main).start()