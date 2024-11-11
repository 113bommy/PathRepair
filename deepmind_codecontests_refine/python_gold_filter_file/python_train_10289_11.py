S=input()
flag = False
if S=="zyxwvutsrqponmlkjihgfedcba":
    T="-1"
elif len(S)<=25:
    for i in range(97,123):
        if chr(i) not in S:
            T=S+chr(i)
            break
else:
    for i in range(2,27):
        for j in range(ord(S[-i])+1,123):
            if chr(j) not in S[:-i]:
                T=S[:-i]+chr(j)
                flag=True
                break
        if flag:
            break
print(T)