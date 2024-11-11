def main():
    (n,m,q) = [int(x) for x in input().split()]
    s = input()
    t = input()
    st1 = [0 for i in range(n+1)]
    st2 = [0 for i in range(n+1)]
    for i in range(m,n+1) :
        if t == s[i-m:i] :
            st1[i-m+1] = 1
            st2[i-1]=1
    for i in range(1,n+1) :
        st1[i] = st1[i-1]+st1[i]
        st2[i] = st2[i-1]+st2[i]
    for i in range(q) :
        (l,r) = [int(x) for x in input().split()]
        if r-l<m-1:
            print(0)
        else :
            print((st1[n]-st1[l-1])-(st2[n]-st2[r-1]))
    
if __name__ == '__main__' :
    main()

    
