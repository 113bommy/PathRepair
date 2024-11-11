def main():
    import sys
    input=sys.stdin.readline
    h,w,k=map(int,input().split())
    S=[]
    for _ in range(h):
        s=list(map(int,list(input().rstrip())))
        S.append(s)
    ans=10**5
    for i in range(2**(h-1)):
        l=[0]
        for j in range(h-1):
            if i&1<<j:
                l.append(l[-1]+1)
            else:
                l.append(l[-1]) 
        ans_=l[-1]
        ll=[0]*h
        j=0
        flag=0
        while j<w:
            for p in range(h):
                ll[l[p]]+=S[p][j]
            if max(ll)>k and flag==0:
                flag=1
                ans_+=1
                ll=[0]*h
            elif max(ll)>k and flag==1:
                ans_=10**5
                break
            else:
                j+=1
                flag=0
        ans=min(ans,ans_)
    print(ans)
if __name__ == '__main__':
    main()