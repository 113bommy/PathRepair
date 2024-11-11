from sys import stdin, setrecursionlimit as srl
from threading import stack_size, Thread

srl(int(1e9)+7)
stack_size(int(1e8))

def solve():
    t = int ( input () )
    for _ in range ( t ) :
        n, k =map(int,input().split())
        l1, r1 = map(int,input().split())
        l2, r2 = map(int, input().split())
        d = min(r1, r2) - max(l1, l2)
        steps = 0
        I = n*(d*(d>0))

        if n*d*(d>0)>=k:
            print(0)
            continue

        if d>=0:
            length = max(r2,r1) - min(l1,l2) - d
            maxpos = length*n
            if maxpos > k-I:
                print(k-I)
            else:
                print(maxpos + (k-I-maxpos)*2)

        else:
            steps+=-d+min(k-I,max(r1,r2)-min(l1,l2))
            I+=min(k-I,max(r1,r2)-min(l1,l2))
            n-=1
            if I<k and n>0:
                p=min((k-I)//(max(r1,r2)-min(l1,l2)),n)
                steps+=p*(max(r1,r2)-min(l1,l2)+abs(d))
                I+=p*(max(r1,r2)-min(l1,l2))
                if I<k and p==n:
                    steps+=(k-I)*2
                elif I<k:
                    method1=abs(d)+k-I
                    method2=2*(k-I)
                    steps+=min(method1,method2)
            elif n==0:
                steps+=2*(k-I)
            print(steps)

        

Thread(target=solve).start()