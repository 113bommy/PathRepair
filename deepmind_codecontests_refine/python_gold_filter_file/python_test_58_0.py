ans=[]
for i in range(int(input())):
    a=int(input())
    s1=input()
    s2=input()
    for i in range(1,a-1):
        if s1[i]==s2[i]=="1":
            ans.append("NO")
            break
    else: ans.append("YES")
for i in ans: print(i)    