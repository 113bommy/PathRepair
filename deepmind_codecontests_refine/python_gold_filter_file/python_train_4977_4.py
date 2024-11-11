import sys
input = sys.stdin.readline

from itertools import accumulate

def main():
    N,X=map(int,input().split())
    A=[list(map(int,input().split())) for i in range(N)]

    A.sort(key=lambda x:x[2]*(X-x[0])+x[0]*x[1],reverse=True)
    ALL=[a[2]*(X-a[0])+a[0]*a[1] for a in A]



    SUM=[0]+list(accumulate(ALL))

    MAX=0
    MINUS=0

    for a,r,l in A:
        MAX+=a
        MINUS+=a*r

    OUT=-1

    def binsearch(score):

        alluse=score//X
        rest=score-alluse*X

        for ri in range(N):
            plus=0
            b,l,u=A[ri]
            
            if rest<b:
                plus+=rest*l
            else:
                plus+=rest*u+b*l-b*u

            if alluse<=ri:
                plus+=SUM[alluse]

            else:
                plus+=SUM[alluse+1]-ALL[ri]

            #print(score,ri,plus)

            if plus>=MINUS:
                return 1

        return 0


    while MAX-OUT>1:
        mid=(MAX+OUT)//2

        if binsearch(mid)==1:
            MAX=mid
        else:
            OUT=mid

    print(MAX)

main()
