for _ in range(int(input())):
    n=int(input())
    s=input()
    if(">" not in s or "<" not in s):
        print(0)
    else:
        ans1 = s.index(">")
        s1=s[::-1]
        ans2 = s1.index("<")
        ans=min(ans1,ans2)
        print(ans)