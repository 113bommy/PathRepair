N=int(input())
s=list(map(int,input().split()))
if N%2==1:
    s.remove(0)
s=list(sorted(s))
if s[0::2]==s[1::2]:
    print((2**((len(s))//2))%(10**9+7))
else:
    print(0)