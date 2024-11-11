n,m=map(int,input().split())
for i in range(n):
    if i%2==0:
        s='#'*m
    elif i%4==1:
        s='.'*(m-1)+'#'
    else:
        s='#'+'.'*(m-1)
    print(s)
#print(n,m)