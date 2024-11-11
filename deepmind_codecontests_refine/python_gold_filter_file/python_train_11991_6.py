from sys  import stdin,stdout
from collections import *
from math import *
st=lambda:list(stdin.readline().strip())
li=lambda:list(map(int,stdin.readline().split()))
mp=lambda:map(int,stdin.readline().split())
inp=lambda:int(stdin.readline())
pr=lambda n: stdout.write(str(n)+"\n")

mod=1000000007

def sub(a,b):
    i=0
    for j in range(len(a)):
        if i<len(b) and a[j]==b[i]:
            i+=1
    return i==len(b)
    

def solve():
    s=st()
    t=st()
    ans=0
    for i in range(len(s)):
        for j in range(i,len(s)):
            new= s[:i]+s[j+1:]
            if sub(new,t):

                ans= max(ans,j-i+1)
    print(ans)
            
 
    
    
for _ in range(1):
    solve()
