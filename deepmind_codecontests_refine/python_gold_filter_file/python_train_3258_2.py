t=int(input())
for q in range(t):
    n=[int(x) for x in input().split()]
    len_k,len_c=n[0],n[1]
    k=[int(x) for x in input().split()]
    c=[int(x) for x in input().split()]
    k=sorted(k)
    s=0
    for i in k:
        s+=c[i-1]
    g=0
    min_score=s
    flag=1
    gift_val=len_c
    for i in range(len_c):
        if i>len_k-1:
            break
        if gift_val==0:
            break
        else:
            gift_val=min(k[-i-1]-1,gift_val-1)
        s-=c[k[-i-1]-1]
        g+=c[i]
        score=s+g
        if min_score>score:
            min_score=score
    print(min_score)