R=lambda:map(int,input().split())
t,=R()
for _ in[0]*t:n,k=R();a=*R(),;print(sum(a[(n-1)//2*k::n//2+1]))