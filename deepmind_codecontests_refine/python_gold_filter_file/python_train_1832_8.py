S=input()
k=0
for i in range(len(S)//2) :
    if S[i]==S[-1-i] :
        1
        
    else :
        k=k+1
if k==1 or len(S)%2!=0 and k==0 :
    print('YES')
else :
    print('NO')
