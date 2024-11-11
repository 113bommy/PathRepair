import sys
q=int(sys.stdin.readline())
for _ in range(q):
    s=sys.stdin.readline()[:-1]
    t=sys.stdin.readline()[:-1]
    #print(set(s))
    #print(set(t),'t')
    if set(t).difference(set(s)):
        print(-1)
    else:
        arr=[{} for _ in range(len(s)+1)]
        cur={}
        for i in range(len(s)-1,-2,-1):
            arr[i]=cur.copy()
            cur[s[i]]=i
        #print(arr,'arr')
        ans=1
        i=-1
        for c in t:
            if c in arr[i]:
                i=arr[i][c]
            else:
                ans+=1
                i=arr[-1][c]
        print(ans)
