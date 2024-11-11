import sys
input = lambda: sys.stdin.readline().rstrip()

t=int(input())
for i in range(t):
    n,a,b=map(int,input().split())
    r=[]
    alpha = [chr(i) for i in range(ord('a'),ord('a') + b)]
    for i in range(n):
        r.append(alpha[i%len(alpha)])
    print(''.join(r))
