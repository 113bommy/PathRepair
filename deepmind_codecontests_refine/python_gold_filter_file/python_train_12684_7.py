def main():
    import sys
    input=sys.stdin.readline
    s=input()
    alpha="abcdefghijklmnopqrstuvwxyz"
    l=len(s)
    alpha2={j:i for i,j in enumerate(alpha)}
    memo=[[0]*26 for _ in range(l,-1,-1)]
    for i in range(26):
        memo[l][i]=l+1
    for x,y in alpha2.items():
        for i in range(l-1,-1,-1):
            if s[i]==x:
                memo[i][y]=i+1
            else:
                memo[i][y]=memo[i+1][y]
    
    search=[1]*(l+2)
    search[l+1]=0
    for i in range(l-1,-1,-1):
        m=max([memo[i][j] for j in range(26)])
        if m!=l+1:
            search[i]=search[m]+1
    
    n,seq=0,0
    ans_len=search[0]
    ans=""
    temp=0
    for i in range(ans_len):
        for j in range(26):
            n=memo[temp][j]
            seq=search[n]+i
            if seq+1==ans_len:
                ans+=alpha[j]
                temp=memo[temp][j]
                break
    print(ans)
if __name__=='__main__':
    main()