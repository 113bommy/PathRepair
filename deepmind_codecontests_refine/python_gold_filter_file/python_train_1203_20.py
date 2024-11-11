S=input()
ma=1
k=1
for i in range(len(S)) :
    if S[i]=='A' or S[i]=='E' or S[i]=='I' or S[i]=='O' or S[i]=='U' or S[i]=='Y' :
        if ma<k :
            ma=k
        k=1
    else :
        k=k+1
if ma<k :
    ma=k
print(ma)
        
    
