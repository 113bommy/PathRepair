import sys
input=sys.stdin.readline

def dist(a,b,c,d,P3):
    for p in P3:
        da,ma=divmod(a,p)
        dc,mc=divmod(c,p)
        if da!=dc:
            return abs(a-c)+abs(b-d)
        if da!=1:
            a,c=ma,mc
            continue
        db,mb=divmod(b,p)
        dd,md=divmod(d,p)
        if abs(db-dd)<2:
            a,c=ma,mc
            continue
        return min(ma+mc+2,2*p-(ma+mc))+abs(b-d)
    return abs(a-c)+abs(b-d)

def main():
    q=int(input())
    P3=[pow(3,i) for i in reversed(range(30))]
    for _ in range(q):
        a,b,c,d=map(lambda x: int(x)-1,input().split())
        print(max(dist(a,b,c,d,P3),dist(b,a,d,c,P3)))

if __name__=='__main__':
    main()