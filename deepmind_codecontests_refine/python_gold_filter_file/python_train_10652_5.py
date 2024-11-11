import math
import string
 
def mult_inp():
    return map(int,input().split(' '))
 
def inp():
    return list(map(int,input().split(' ')))
 
def binn(dp,it):
    left = 0
    right = len(dp)
    while left <= right:
        mid = (left + right)//2
        if dp[mid] == it:
            return mid
        elif dp[mid] < it:
            left = mid + 1
        else:
            right = mid - 1
    return -1
def is_pow2(x):
    flag = [0] * 64
    for i in range(64):
        flag[i] = 2**i
    if x in flag:
        return True
    return False
 
def is_pow3(x):
    cubes=[0]*10001
    for i in range(1,10001):
        cubes[i]=i**3
    if(binn(cubes,x)!=-1):
        return True
    return False
 
def solve():
    S=list(input())
    a=[]
    for i in S:
        a.append(int(ord(i))-97)
    
    n=len(S)
    if 'a' not in(S):
        print("no")
    else:
        s,e=0,0
        cur=0
        for i in range(n):
            if S[i]=='a':
                s,e=i,i
                break
        while 1:
            if cur==n-1:
                print('yes')
                break
            elif s+1<n and cur+1==a[s+1]:
                cur+=1
                s+=1
            elif e-1>-1 and cur+1==a[e-1]:
                cur+=1
                e-=1
            else:
                print('no')
                break
            
        
    
        
t=int(input())
for _ in range(t):
    solve()