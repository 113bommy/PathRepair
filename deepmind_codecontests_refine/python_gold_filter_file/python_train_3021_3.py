#coding:UTF-8
def chain(p,n):
    m={}
    for i in range(1,n+1):
        m[i] = {i:0}
         
    for l in range(2,n+1):
        for i in range(1,n-l+2):
            j = i + l -1
            m[i][j] = float("inf")
            for k in range(i,j):
                m[i][j] = min(m[i][j],m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j])
    print(m[1][n])
    
if __name__=="__main__": 
    p={}
    n = int(input())
    for i in range(1,n+1):
        st = input()
        w = st.split()
        p[i-1] = int(w[0])
        p[i]   = int(w[1])
    chain(p,n)