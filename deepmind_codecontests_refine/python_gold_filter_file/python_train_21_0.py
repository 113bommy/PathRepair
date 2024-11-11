def main():
    t=int(input())
    for _ in range(t):
        n,l,r=map(int,input().split())
        if l==n*n-n+1:
            print(1)
            continue
        if r==n*n-n+1:
            r_g=n
        for i in range(n-1):
            if l>2*n-2-2*i:
                l-=2*n-2-2*i
            else:
                l_g=i+1
                break
        for i in range(n-1):
            if r>2*n-2-2*i:
                r-=2*n-2-2*i
            else:
                r_g=i+1
                break
        ans=[]
        for i in range(l_g,min(r_g+1,n)):
            for j in range(i+1,n+1):
                ans.append(i)
                ans.append(j)
        if r_g==n:
            ans.append(1)
        if r_g==n or r==2*n-2*r_g:
            print(*ans[l-1:])
        else:
            print(*ans[l-1:r+2*r_g-2*n])
if __name__ == '__main__':
    main()