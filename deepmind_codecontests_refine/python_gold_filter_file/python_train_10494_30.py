N,A,B,C,D=map(int,input().split())
S=input()
s=list(S.split("#"))

answer="Yes"


if "##" in S[min(A,C):max(B,D)]:
    answer="No"
if C<D:
    pass
else:
    if "..." not in S[B-2:D+1]:
        answer="No"
    
print(answer)
    
            
    