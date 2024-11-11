S=input().split('a')
ma=1000000000000
R='abcdefghijklmnopqrstuvwxyz'
for x in S :
    if len(x)>0 :
        ma=len(x)
        break
S1=''
c=1
p=len(S)
for x in S :
    if len(x)==ma and c==1 :
        c=0
        for i in range(len(x)) :
            S1=S1+R[R.index(x[i])-1]
    else :
        S1=S1+x
    if p!=1 :
        S1=S1+'a'
        p=p-1
    
if S1.count('a')==len(S1) and c==1 :
    S1=S1[:len(S)-2]+'z'
print(S1)
    
        
    
