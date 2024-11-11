n,k=map(int,input().split())
n=list(str(n))
for i in range (k):
    if n[-1]=='0':
        n.pop(-1)
    else:
        n[-1]=str(int(n[-1])-1)
n[-1]=str(n[-1])
print(''.join(n))