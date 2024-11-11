def f(al,ii):
    st=False
    cr=0
    for i in al:
        i.sort()
        if not st and (ii<i[0] or ii>i[1]):
            continue
        else:
            st=True
            if cr==0:
                cr=i
            #print(cr,i)
            tpp=[cr,i]
            tpp.sort()
            if tpp[-1][0]<=tpp[0][1]:
                tp=merge(tpp)
                if len(tp)==1:
                    tp[0].sort()
                    cr=tp[0]
    return cr
    
    
def merge(intervals):
 
    intervals.sort(key=lambda x: x[0])
 
    merged = []
    for interval in intervals:
        # if the list of merged intervals is empty or if the current
        # interval does not overlap with the previous, simply append it.
        if not merged or merged[-1][1] < interval[0]:
            merged.append(interval)
        else:
        # otherwise, there is overlap, so we merge the current and previous
        # intervals.
            merged[-1][1] = max(merged[-1][1], interval[1])
 
    return merged
    
    
for tc in range(int(input())):
    al=list(map(int,input().split()))
    x=al[1]
    m=al[2]
    al=[]
    for j in range(m):
        al.append(list(map(int,input().split())))
    tt=(f(al,x))
    if tt==0:
        print(1)
    else:
        print(tt[1]-tt[0]+1)