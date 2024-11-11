S=input()
k=0
for i in range(2) :
    if i==0 :
        if S[i]=='0' :
            k=k+2
        if S[i]=='1' :
            k=k+7
        if S[i]=='2' :
            k=2
        if S[i]=='3' :
            k=3
        if S[i]=='4' :
            k=3
        if S[i]=='5' :
            k=4
        if S[i]=='6' :
            k=2
        if S[i]=='7' :
            k=5
        if S[i]=='8' :
            k=1
        if S[i]=='9' :
            k=2
    else :
        if S[i]=='0' :
            k=k*2
        if S[i]=='1' :
            k=k*7
        if S[i]=='2' :
            k=k*2
        if S[i]=='3' :
            k=k*3
        if S[i]=='4' :
            k=k*3
        if S[i]=='5' :
            k=k*4
        if S[i]=='6' :
            k=k*2
        if S[i]=='7' :
            k=k*5
        if S[i]=='8' :
            k=k*1
        if S[i]=='9' :
            k=k*2
print(k)
        
