import sys, os.path
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

l,r=map(int,input().split())
if (r-l)<=1:
    print(l) 
else:
    print(2)    
