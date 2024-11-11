from sys import stdin,stdout
input = stdin.readline
# import io,os
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def im():
    return map(int,input().split())
def ii():
    return int(input())
def il():
    return list(map(int,input().split()))
def ins():
    return input()[:-1]

def check(lis):    
    for i in range(1,len(lis)):
        if lis[i]<=lis[i-1]:
            return False
    return True
    
for _ in range(ii()):
    n = ii()
    lis = il()
    if check(lis): print(0)
    elif lis[0]==1 or lis[-1]==n: print(1)
    elif lis[0]==n and lis[-1]==1: print(3)
    else: print(2)