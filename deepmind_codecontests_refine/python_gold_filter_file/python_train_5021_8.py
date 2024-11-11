#import io,os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    #for _ in range(int(input())):
    n = int(input())
    s = input()
    cnt = defaultdict(int)
    for i in range(n):
        cnt[s[i]] += 1
    if cnt["("] != cnt[")"]:
        print(-1)
        exit()
    
    ans = 0
    bal = 0
    bad = False
    last = 0
    for i in range(n):
        if s[i] == "(":
            bal += 1
        else:
            bal -= 1
        if bal == 0:
            if bad:
                ans += i - last + 1
                last = i + 1
                bad = False
            else:
                last = i + 1
                bad = False
        elif bal < 0:
                bad = True
                
            
    print(min(n, ans))

    
main()