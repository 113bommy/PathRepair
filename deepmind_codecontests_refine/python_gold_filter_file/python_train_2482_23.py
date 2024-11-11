Sd=input().strip()
T=input().strip()
S=""
for i in range(len(Sd)-len(T),-1,-1):
    sub=Sd[i:i+len(T)]
    for t,s in zip(T,sub):
        if s!="?" and s!=t:
            break
    else:
        S=Sd[:i]+T+Sd[i+len(T):]
        break
if S != "":
    print(S.replace("?", "a"))
else:
    print("UNRESTORABLE")