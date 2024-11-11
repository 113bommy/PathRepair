import sys

from collections import defaultdict

def main():

    n,q = list(map(int, sys.stdin.readline().split()))

    al = 0
    d = defaultdict(list)
    sts = defaultdict(int)
    cur = 0
    msgs = []
    ans = []
    start = 0
    for i in range(q):
        t,x = list(map(int, sys.stdin.readline().split()))
        if t == 1:
            al+=1
            d[x].append(al)
            msgs.append(x)
            cur+=1
        elif t==2:
            size = len(d[x])
            if size >0:
                cur -= size - sts[x]
                d[x] = list()
                sts[x] = 0
        else :  
            if start<x:                      
                for i in range(start,x):                    
                    v = msgs[i]
                    dd = d[v]
                    size = len(dd)
                    cur_st = sts[v]
                    while size>cur_st and dd[cur_st]<=x:
                        cur_st+=1
                        cur-=1
                    sts[v] = cur_st                                  
                start = x
        ans.append(cur)   

  
    print("\n".join(map(str,ans)))

main()
