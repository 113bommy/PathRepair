from collections import defaultdict as dd
t=int(input())
for _ in range(t):
    s=input()
    mct=0
    for i in range(10):
        for j in range(10):
            ct=0
            flag=1
            for k in range(len(s)):
                if flag:
                    if int(s[k])==i:
                        ct+=1
                        flag^=1
                else:
                    if int(s[k])==j:
                        ct+=1
                        flag^=1
            if i==j:
                mct=max(mct,ct)
            else:
                mct=max(mct,ct-(ct%2))
    print(len(s)-mct)