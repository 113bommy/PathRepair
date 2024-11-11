n,a,b,c,d=map(int,input().split())
s=input()
if s[a-1:max(c,d)].count("##")>0:
    print("No")
elif c<d:
    print("Yes")
else:
    if "..." in s[b-2:d+1]:
        print("Yes")
    else:
        print("No")
