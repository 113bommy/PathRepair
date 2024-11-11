n=int(input())
S=input()
S1=''
if n==12 :
    if S[0]>'1' :
        if S[1]!='0' :
            S1=S1+'0'
        else :
            S1=S1+'1'
    else :
        if S[0]!='0' or S[1]!='0' :
            S1=S1+S[0]
        
    if S[1]>'2' and S1[0]>'0' :
        S1=S1+'1'
    else :
        if S[0]!='0' or S[1]!='0' :
            S1=S1+S[1]
    if S[0]=='0' and S[1]=='0' :
        if S[0]=='0' and S[1]=='0' :
            S1='01'
        else :
            S1='10'
    S1=S1+':'
    if S[3]>'5' :
        S1=S1+'0'
    else :
        S1=S1+S[3]
    S1=S1+S[4]
    
if n==24 :
    if S[0]>'2' :
        S1=S1+'0'
    else :
        S1=S1+S[0]
    if S[0]=='2' :
        if S[1]>'3' :
            S1=S1+'0'
        else :
            S1=S1+S[1]
    else :
        S1=S1+S[1]
    S1=S1+':'
    if S[3]>'5' :
        S1=S1+'0'
    else :
        S1=S1+S[3]
    S1=S1+S[4]

print(S1)
        
    
