import sys
import math
from sys import stdin, stdout
 
# TAKE INPUT
def get_ints_in_variables():
    return map(int, sys.stdin.readline().strip().split())
def get_int(): return int(input())
def get_ints_in_list(): return list(
    map(int, sys.stdin.readline().strip().split()))
def get_list_of_list(n): return [list(
    map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
def get_string(): return sys.stdin.readline().strip()
 
def main():
    # Write Your Code Here
    for _ in range(get_int()):
        n,a,b = get_ints_in_variables()
        lb = math.ceil(n/2)-1
        ans = [0 for i in range(n+1)]
        if abs(a-b) > 1:
            print(-1)
            # return
        elif lb >= a and lb >= b and (a+b) <= n-2:
            if a>b:
                cnt = n
                cnt_loop = a
                i = 2
                while i < n+1 and cnt_loop > 0:
                    ans[i] = cnt
                    cnt -= 1
                    cnt_loop -= 1
                    i += 2
                
                i = 1
                while i < n+1:
                    if ans[i] == 0:
                        ans[i] = cnt
                        cnt -= 1
                    i += 1
            elif b > a:
                cnt = 1
                cnt_loop = b
                i = 2
                while i < n+1 and cnt_loop > 0:
                    ans[i] = cnt
                    cnt += 1
                    cnt_loop -= 1
                    i += 2
                
                i = 1
                while i < n+1:
                    if ans[i] == 0:
                        ans[i] = cnt
                        cnt += 1
                    i += 1
            else:
                cnt = n
                cnt_loop = a
                i = 2
                while i < n+1 and cnt_loop > 0:
                    ans[i] = cnt
                    cnt -= 1
                    cnt_loop -= 1
                    i += 2
                
                cnt=  1
                i = 1
                while i < n+1:
                    if ans[i] == 0:
                        ans[i] = cnt
                        cnt += 1
                    i += 1

            for i in range(1, n+1):
                print(ans[i],end=" ")
            print()
        else:
            print(-1)
            
#  calling main Function
if __name__ == "__main__":
    main()