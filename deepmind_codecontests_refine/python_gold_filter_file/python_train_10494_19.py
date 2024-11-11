n,a,b,c,d = map(int,input().split())
s=input()+"."
if c<d or (c>d and "..." in s[b-2:d+1]):
    if "##" not in s[b:d] and "##" not in s[a:c]:
        print("Yes")
    else:
        print("No")
else:
    print("No")