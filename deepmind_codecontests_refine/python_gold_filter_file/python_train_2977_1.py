n,k=list(map(int,input().split()))
j=2
li=list()
c=1
while c<k and n!=1:
    if n%j==0:
        li.append(j)
        n=n//j
        c+=1
    else: j+=1
    #print(c,li)
    #input()
if n!=1: li.append(n)
if len(li)<k: print(-1)
else: print(' '.join(list(map(str,li))))
    
