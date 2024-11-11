import math
from itertools import combinations as cb
from itertools import permutations as pr
from collections import defaultdict as df
from collections import deque as dq
def ispalindrome(s,n):
    cnt0,cnt1=0,0
    for i in range(n):
        if s[i]=='1':
            cnt1+=1
#         a.append(s[i])
    cnt0=n-cnt1
    al,bo=0,0
    if cnt1==n:
        return('DRAW')
    else:
        if cnt0==1 or cnt0%2==0:
            return('BOB')
        else:
            return('ALICE')
for _ in range(int(input())):
    n=int(input())
    s=input()
    if s==s[::-1]:
        print(ispalindrome(s,n))
    else:
        cnt0,cnt1=0,0
        a=[]
        for i in range(n):
            if s[i]=='0':
                cnt0+=1
            a.append(s[i])
        b=a.copy()
        c=a.copy()
        if cnt0==1:
            print('ALICE')
        elif cnt0==2:
            # result=False
            for i in range(n):
                if b[i]=='0':
                    b[i]='1'
                    break
            b=''.join(b)
            for i in range(n-1,-1,-1):
                if c[i]=='0':
                    c[i]='1'
                    break
            c=''.join(c)
            if b==b[::-1] or c==c[::-1]:
                print('DRAW')
            else:
                print('ALICE')
        else:
            print('ALICE')
                    
            
                