from sys import stdin,stdout
import math
input=stdin.readline
def print(x='',end='\n'):
    stdout.write(str(x)+end)

def solve():
    a,b,n=map(int,input().split())

    count=0
    flag=0
    a,b=min(a,b),max(a,b)
    while True:
        if a>n or b>n:
            break
        if flag:
            b+=a
            flag=0
        else:
            a+=b
            flag=1
        count+=1
    print(count)



test=1
test=int(input())
for __ in range(test):
    solve()
