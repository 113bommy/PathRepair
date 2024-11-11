#import sys
#sys.stdin = open("input.in","r")
#sys.stdout = open("test.out","w")
n=int(input())
a=list(map(int,input().split()))
l=2*sum(a)//n
if l > max(a):
    print(l + 1)
elif l < max(a):
    print(max(a))
else:
    print(l + 1)