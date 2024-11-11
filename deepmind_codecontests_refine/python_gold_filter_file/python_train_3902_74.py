n,m=map(int,input().split())
for j in range(n):
    print(['#'*m,'.'*(m-1)+'#','#'*m,'#'+'.'*(m-1)][j%4])