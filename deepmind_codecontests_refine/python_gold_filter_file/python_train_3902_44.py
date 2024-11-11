s,m=map(int,input().split())
for i in range(s):
    print(['#'*m,'.'*(m-1)+'#','#'*m,'#'+'.'*(m-1)][i%4])